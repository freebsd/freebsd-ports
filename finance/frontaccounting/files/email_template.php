<?php
/*
 * Example for the optional company email-template hook.
 * Copy to company/<company-id>/reporting/email_template.php.
 * Requires the pdf_report.inc email-template hook patch; this is not a
 * standard feature of unpatched FrontAccounting 2.4.20.
 *
 * The file must return a callable. It is loaded separately for each contact.
 * Return array() to keep the standard email. Optional return keys:
 *   body   - introductory text, ending with two newlines
 *   sender - signature details (without a closing greeting)
 * FrontAccounting adds payment links, "Kindest regards", and the signature.
 * Recipients, subject and attachments are handled by FrontAccounting.
 * Do not echo, send mail, or modify database records here.
 *
 * CALLBACK FIELD REFERENCE -- FrontAccounting 2.4.20 + this port's hook
 * ==================================================================
 * Use $contact['email'], $formData['reference'], etc.; array keys are NOT
 * separate variables. Names are case-sensitive (including DebtorName and
 * StockItemName). Use ?? or isset(): fields can be absent, null or empty.
 * Database numbers/flags can be strings. Dates normally use YYYY-MM-DD;
 * format them for display rather than assuming they are localized.
 *
 * These are the standard source fields, not a guarantee that every report
 * supplies every key. Custom reports, company headers and extensions can
 * add/replace fields. In particular, $company is an extensible preference
 * map, so no fixed list can describe every installation.
 *
 * $contact -- the current email recipient (one callback per contact)
 * ----------------------------------------------------------------
 * Standard crm_persons fields:
 *   id          Contact/person record ID (not an invoice/customer ID).
 *   ref         Contact reference/short name.
 *   name        First contact name field.
 *   name2       Second contact name field; may be empty.
 *   address     Contact postal address.
 *   phone       Primary contact phone number.
 *   phone2      Alternative contact phone number.
 *   fax         Contact fax number.
 *   email       Recipient email address; changing this argument does not
 *               change the address used by the renderer to send the mail.
 *   lang        Contact language code.
 *   notes       Internal contact notes; do not include by default.
 *   inactive    Contact inactivity flag.
 * Depending on which standard contact query the report uses, also:
 *   type        Relationship class, e.g. customer, cust_branch, supplier.
 *   action      Contact purpose, e.g. invoice, order, delivery, general.
 *   ext_type    Combined type.action (branch contact queries).
 *   contact_id  Relationship record ID (get_crm_persons queries).
 *   description, system
 *               Contact-category description and system-category flag
 *               (get_crm_persons joins crm_categories with crm_persons).
 * Numeric SQL-result indexes may also exist; use named keys instead.
 *
 * $formData -- document/header data, NOT the complete transaction row
 * -----------------------------------------------------------------
 * Prepared by SetCommonData and the standard doctext.inc header:
 *   doctype         Document type; sales invoice = 10. This is distinct
 *                   from the source transaction's type field below.
 *   document_name   Localized label, e.g. "Invoice No.".
 *   document_number Display number/reference selected by report settings.
 *   document_date   Document date selected by the header.
 *   document_amount Initially ov_amount + ov_freight + ov_gst. Do not
 *                   assume a universally valid payable balance: headers
 *                   can overwrite it (stock sales-order header does so).
 *   recipient_name  Name selected for the document's primary address.
 *   rep_lang        Report language, taken from the first supplied contact;
 *                   may differ from this recipient's $contact['lang'].
 *   domicile        Company domicile, added for invoices/statements.
 *
 * All source-row keys copied by SetCommonData, only when present/non-null:
 *   Identifiers/references:
 *     order_no, reference, id, trans_no, type, order_, wo_ref, debtor_ref,
 *     requisition_no
 *   Dates:
 *     ord_date, date_, tran_date, delivery_date, due_date, required_by
 *   Party/location/item data:
 *     name, location_name, delivery_address, supp_name, address,
 *     DebtorName, supp_account_no, tax_id, contact, StockItemName
 *   Amounts/settings:
 *     ov_freight, ov_gst, ov_amount, prepaid, payment_terms, curr_code,
 *     units_issued
 *   payment_terms is an ID, not the payment-terms description.
 *   prepaid may be converted to "partial" or "final" by the invoice header.
 *
 * Additional keys copied from the other SetCommonData arguments:
 *   Customer branch: br_address, br_name, salesman, disable_branch
 *   Sales order:     deliver_to, delivery_address, customer_ref
 *   Bank account:    bank_name, bank_account_number, payment_service
 *   salesman is an ID, not the salesperson's name. A bank account or
 *   payment service is only present when the report supplies that data.
 *   Later arguments can overwrite an earlier key such as delivery_address.
 *
 * $company -- current company's get_company_prefs() / sys_prefs values
 * -----------------------------------------------------------------
 * Common fields for customer-facing text:
 *   coy_name        Company name.
 *   postal_address  Company postal address (may contain line breaks).
 *   phone, fax, email
 *                   Company contact details.
 *   coy_no          Company registration number.
 *   gst_no          Company tax/VAT registration number.
 *   domicile        Registered domicile text.
 *   coy_logo        Logo filename, not an image attachment or URL.
 *   curr_default    Company base currency code; use formData.curr_code for
 *                   the document currency when available.
 *   legal_text      Configured legal/footer text.
 *   bcc_email       Internal BCC setting; not customer-facing text.
 *
 * Other preference keys seeded by the stock 2.4.20 en_US-new.sql database
 * (settings/account codes, not automatically formatted descriptions):
 *   tax_prd, tax_last, use_dimension, f_year, shortname_name_in_list,
 *   no_item_list, no_customer_list, no_supplier_list, base_sales, time_zone,
 *   add_pct, round_to, login_tout, past_due_days, profit_loss_year_act,
 *   retained_earnings_act, bank_charge_act, exchange_diff_act, tax_algorithm,
 *   default_credit_limit, accumulate_shipping, freight_act, debtors_act,
 *   default_sales_act, default_sales_discount_act, default_prompt_payment_act,
 *   default_delivery_required, default_receival_required, default_quote_valid_days,
 *   default_dim_required, pyt_discount_act, creditors_act, po_over_receive,
 *   po_over_charge, allow_negative_stock, default_inventory_act, default_cogs_act,
 *   default_adj_act, default_inv_sales_act, default_wip_act,
 *   default_workorder_required, version_id, auto_curr_reval, grn_clearing_act,
 *   deferred_income_act, gl_closing_date, alternative_tax_include_on_docs,
 *   no_zero_lines_amount, show_po_item_codes, accounts_alpha, loc_notification,
 *   print_invoice_no, allow_negative_prices, print_item_images_on_quote,
 *   suppress_tax_rates, company_logo_report, barcodes_on_stock,
 *   print_dialog_direct, ref_no_auto_increase, default_loss_on_asset_disposal_act,
 *   depreciation_period, use_manufacturing, dim_on_recurrent_invoice,
 *   long_description_invoice, max_days_in_docs, use_fixed_assets,
 *   company_logo_on_views
 * An upgraded database can have additional preferences, and custom charts
 * of accounts can seed different values. Use ?? for optional preferences.
 *
 * $user -- string: display name of the logged-in user generating the report.
 * It is not a user object, username, email address or database connection.
 *
 * Not supplied as callback arguments:
 *   PDF bytes/path, invoice line items, attachments, email subject, mail
 *   object, full customer record, passwords or database connection details.
 *   $this is unavailable in this static callback. The renderer's local
 *   variables do not become callback variables automatically.
 *
 * Variables created by this example below (not additional FA input fields):
 *   $name, $reference, $greeting, $document, $body, $address, $addressLines,
 *   $signature. The nested array_filter callback uses its own $line argument.
 *
 * To inspect a custom installation, examine array_keys($contact),
 * array_keys($formData) and array_keys($company) in a private test harness.
 * Do not echo/debug-dump them into a customer email or a public web page.
 *
 * Source references in the stock 2.4.20 archive:
 *   reporting/includes/pdf_report.inc: constructor, SetCommonData, End
 *   reporting/includes/doctext.inc
 *   sales/includes/db/branches_db.inc: get_branch_contacts
 *   includes/db/crm_contacts_db.inc: get_crm_persons
 *   admin/db/company_db.inc: get_company_prefs
 *   sql/en_US-new.sql: crm_persons, crm_categories, sys_prefs
 */
return static function ($contact, $formData, $company, $user) {
    // FrontAccounting transaction type 10 is a sales invoice.
    // Leave other document types unchanged.
    if (($formData['doctype'] ?? null) != 10) {
        return array();
    }

    $name = trim(($contact['name'] ?? '') . ' ' . ($contact['name2'] ?? ''));

    $reference = (string) ($formData['reference'] ?? $formData['document_number'] ?? '');

    $greeting = $name !== '' ? 'Hello ' . $name . ',' : 'Hello,';

    $document = $reference !== '' ? 'invoice ' . $reference : 'your invoice';

    // Replace these paragraphs with your preferred wording.
    $body = $greeting . "\n\n";
    $body .= "Thank you for your business.\n\n";
    $body .= 'Please find attached ' . $document . " in PDF format.\n\n";
    $body .= "If you have any questions, please reply to this email.\n\n";

    // Use this installation's own settings, with one address line per line.
    // No organization names, addresses or contact details are embedded here.
    $address = str_replace(array("\r\n", "\r"), "\n", $company['postal_address'] ?? '');

    $addressLines = array_filter(array_map('trim', explode("\n", $address)),
        static function ($line) { return $line !== ''; });

    $signature = array_merge(
        array($user, $company['coy_name'] ?? ''),
        array_values($addressLines),
        array($company['email'] ?? '', $company['phone'] ?? '')
    );
    
    $signature = array_filter(array_map('trim', $signature),
        static function ($line) { return $line !== ''; });

    return array('body' => $body, 'sender' => implode("\n", $signature));
};
