# New ports collection makefile for:	drill
# Date created:        29 December 2005
# Whom:                Konstantin Saurbier <saurbier@math.uni-bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	ldns
PORTVERSION=	1.6.3
CATEGORIES=	dns
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/

MAINTAINER=	konstantin@saurbier.net
COMMENT=	A library for programs conforming to DNS RFCs and drafts

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

OPTIONS=	DOCS "With documentation" Off \
		EXAMPLES "With example programs" Off

.include <bsd.port.pre.mk>

ALL_TARGET=	all
INSTALL_TARGET=	install-lib install-h

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
ALL_TARGET+=	doc
INSTALL_TARGET+=install-manpages

NOMANCOMPRESS=	true
MANCOMPRESSED=	no
MAN3=	ldns_bget_token.3 ldns_bgetc.3 ldns_bskipcs.3 ldns_buffer.3 \
	ldns_buffer2pkt_wire.3 ldns_buffer_at.3 ldns_buffer_available.3 \
	ldns_buffer_available_at.3 ldns_buffer_begin.3 \
	ldns_buffer_capacity.3 ldns_buffer_clear.3 ldns_buffer_current.3 \
	ldns_buffer_end.3 ldns_buffer_export.3 ldns_buffer_flip.3 \
	ldns_buffer_free.3 ldns_buffer_limit.3 ldns_buffer_new.3 \
	ldns_buffer_new_frm_data.3 ldns_buffer_position.3 \
	ldns_buffer_printf.3 ldns_buffer_read.3 ldns_buffer_read_at.3 \
	ldns_buffer_read_u16.3 ldns_buffer_read_u16_at.3 \
	ldns_buffer_read_u32.3 ldns_buffer_read_u32_at.3 \
	ldns_buffer_read_u8.3 ldns_buffer_read_u8_at.3 \
	ldns_buffer_remaining.3 ldns_buffer_remaining_at.3 \
	ldns_buffer_reserve.3 ldns_buffer_rewind.3 \
	ldns_buffer_set_capacity.3 ldns_buffer_set_limit.3 \
	ldns_buffer_set_position.3 ldns_buffer_skip.3 \
	ldns_buffer_status.3 ldns_buffer_status_ok.3 ldns_buffer_write.3 \
	ldns_buffer_write_at.3 ldns_buffer_write_string.3 \
	ldns_buffer_write_string_at.3 ldns_buffer_write_u16.3 \
	ldns_buffer_write_u16_at.3 ldns_buffer_write_u8.3 \
	ldns_buffer_write_u8_at.3 ldns_calc_keytag.3 ldns_create_nsec.3 \
	ldns_dname.3 ldns_dname2canonical.3 ldns_dname_cat.3 \
	ldns_dname_cat_clone.3 ldns_dname_compare.3 ldns_dname_interval.3 \
	ldns_dname_is_subdomain.3 ldns_dname_label.3 \
	ldns_dname_label_count.3 ldns_dname_left_chop.3 ldns_dname_new.3 \
	ldns_dname_new_frm_data.3 ldns_dname_new_frm_str.3 \
	ldns_dname_str_absolute.3 ldns_dnssec_build_data_chain.3 \
	ldns_dnssec_data_chain.3 ldns_dnssec_data_chain_deep_free.3 \
	ldns_dnssec_data_chain_free.3 ldns_dnssec_data_chain_new.3 \
	ldns_dnssec_data_chain_print.3 ldns_dnssec_data_chain_struct.3 \
	ldns_dnssec_derive_trust_tree.3 \
	ldns_dnssec_derive_trust_tree_dnskey_rrset.3 \
	ldns_dnssec_derive_trust_tree_ds_rrset.3 \
	ldns_dnssec_derive_trust_tree_no_sig.3 \
	ldns_dnssec_derive_trust_tree_normal_rrset.3 ldns_dnssec_name.3 \
	ldns_dnssec_name_add_rr.3 ldns_dnssec_name_cmp.3 \
	ldns_dnssec_name_find_rrset.3 ldns_dnssec_name_free.3 \
	ldns_dnssec_name_name.3 ldns_dnssec_name_new.3 \
	ldns_dnssec_name_new_frm_rr.3 \
	ldns_dnssec_name_node_next_nonglue.3 ldns_dnssec_name_print.3 \
	ldns_dnssec_name_set_name.3 ldns_dnssec_name_set_nsec.3 \
	ldns_dnssec_remove_signatures.3 ldns_dnssec_rrs.3 \
	ldns_dnssec_rrs_add_rr.3 ldns_dnssec_rrs_free.3 \
	ldns_dnssec_rrs_new.3 ldns_dnssec_rrs_print.3 \
	ldns_dnssec_rrsets.3 ldns_dnssec_rrsets_add_rr.3 \
	ldns_dnssec_rrsets_free.3 ldns_dnssec_rrsets_new.3 \
	ldns_dnssec_rrsets_print.3 ldns_dnssec_rrsets_set_type.3 \
	ldns_dnssec_rrsets_type.3 ldns_dnssec_trust_tree.3 \
	ldns_dnssec_trust_tree_add_parent.3 \
	ldns_dnssec_trust_tree_contains_keys.3 \
	ldns_dnssec_trust_tree_depth.3 ldns_dnssec_trust_tree_free.3 \
	ldns_dnssec_trust_tree_new.3 ldns_dnssec_trust_tree_print.3 \
	ldns_dnssec_trust_tree_print_sm.3 ldns_dnssec_verify_denial.3 \
	ldns_dnssec_verify_denial_nsec3.3 ldns_dnssec_zone.3 \
	ldns_dnssec_zone_add_empty_nonterminals.3 \
	ldns_dnssec_zone_add_rr.3 ldns_dnssec_zone_create_nsecs.3 \
	ldns_dnssec_zone_create_rrsigs.3 ldns_dnssec_zone_find_rrset.3 \
	ldns_dnssec_zone_free.3 ldns_dnssec_zone_mark_glue.3 \
	ldns_dnssec_zone_names_print.3 ldns_dnssec_zone_new.3 \
	ldns_dnssec_zone_print.3 ldns_dnssec_zone_sign.3 \
	ldns_dnssec_zone_sign_nsec3.3 ldns_fget_token.3 ldns_fskipcs.3 \
	ldns_get_errorstr_by_id.3 ldns_get_rr_class_by_name.3 \
	ldns_get_rr_list_addr_by_name.3 ldns_get_rr_list_hosts_frm_file.3 \
	ldns_get_rr_list_hosts_frm_fp.3 ldns_get_rr_list_hosts_frm_fp_l.3 \
	ldns_get_rr_list_name_by_addr.3 ldns_get_rr_type_by_name.3 \
	ldns_getaddrinfo.3 ldns_init_random.3 ldns_is_rrset.3 ldns_key.3 \
	ldns_key2buffer_str.3 ldns_key2rr.3 ldns_key2str.3 \
	ldns_key_algorithm.3 ldns_key_buf2dsa.3 ldns_key_buf2rsa.3 \
	ldns_key_deep_free.3 ldns_key_dsa_key.3 ldns_key_expiration.3 \
	ldns_key_flags.3 ldns_key_free.3 ldns_key_hmac_key.3 \
	ldns_key_inception.3 ldns_key_keytag.3 ldns_key_list_free.3 \
	ldns_key_list_key.3 ldns_key_list_key_count.3 ldns_key_list_new.3 \
	ldns_key_list_pop_key.3 ldns_key_list_push_key.3 \
	ldns_key_list_set_key_count.3 ldns_key_new.3 \
	ldns_key_new_frm_algorithm.3 ldns_key_new_frm_fp.3 \
	ldns_key_new_frm_fp_dsa.3 ldns_key_new_frm_fp_dsa_l.3 \
	ldns_key_new_frm_fp_l.3 ldns_key_new_frm_fp_rsa.3 \
	ldns_key_new_frm_fp_rsa_l.3 ldns_key_origttl.3 ldns_key_print.3 \
	ldns_key_pubkey_owner.3 ldns_key_rr2ds.3 ldns_key_rsa_key.3 \
	ldns_key_set_algorithm.3 ldns_key_set_dsa_key.3 \
	ldns_key_set_expiration.3 ldns_key_set_flags.3 \
	ldns_key_set_hmac_key.3 ldns_key_set_inception.3 \
	ldns_key_set_keytag.3 ldns_key_set_origttl.3 \
	ldns_key_set_pubkey_owner.3 ldns_key_set_rsa_key.3 \
	ldns_native2rdf_int16.3 ldns_native2rdf_int16_data.3 \
	ldns_native2rdf_int32.3 ldns_native2rdf_int8.3 ldns_octet.3 \
	ldns_pkt.3 ldns_pkt2buffer_str.3 ldns_pkt2buffer_wire.3 \
	ldns_pkt2str.3 ldns_pkt2wire.3 ldns_pkt_aa.3 ldns_pkt_ad.3 \
	ldns_pkt_additional.3 ldns_pkt_ancount.3 ldns_pkt_answer.3 \
	ldns_pkt_answerfrom.3 ldns_pkt_arcount.3 ldns_pkt_authority.3 \
	ldns_pkt_cd.3 ldns_pkt_edns.3 ldns_pkt_edns_data.3 \
	ldns_pkt_edns_extended_rcode.3 ldns_pkt_edns_udp_size.3 \
	ldns_pkt_edns_version.3 ldns_pkt_edns_z.3 ldns_pkt_free.3 \
	ldns_pkt_get_opcode.3 ldns_pkt_get_rcode.3 \
	ldns_pkt_get_section_clone.3 ldns_pkt_id.3 ldns_pkt_new.3 \
	ldns_pkt_nscount.3 ldns_pkt_print.3 ldns_pkt_qdcount.3 \
	ldns_pkt_qr.3 ldns_pkt_query_new.3 ldns_pkt_query_new_frm_str.3 \
	ldns_pkt_querytime.3 ldns_pkt_question.3 ldns_pkt_ra.3 \
	ldns_pkt_rd.3 ldns_pkt_reply_type.3 ldns_pkt_rr_list_by_name.3 \
	ldns_pkt_rr_list_by_name_and_type.3 ldns_pkt_rr_list_by_type.3 \
	ldns_pkt_section.3 ldns_pkt_set_aa.3 ldns_pkt_set_ad.3 \
	ldns_pkt_set_ancount.3 ldns_pkt_set_answerfrom.3 \
	ldns_pkt_set_arcount.3 ldns_pkt_set_cd.3 ldns_pkt_set_edns_data.3 \
	ldns_pkt_set_edns_extended_rcode.3 ldns_pkt_set_edns_udp_size.3 \
	ldns_pkt_set_edns_version.3 ldns_pkt_set_edns_z.3 \
	ldns_pkt_set_flags.3 ldns_pkt_set_id.3 ldns_pkt_set_nscount.3 \
	ldns_pkt_set_opcode.3 ldns_pkt_set_qdcount.3 ldns_pkt_set_qr.3 \
	ldns_pkt_set_querytime.3 ldns_pkt_set_ra.3 ldns_pkt_set_rcode.3 \
	ldns_pkt_set_rd.3 ldns_pkt_set_section_count.3 \
	ldns_pkt_set_size.3 ldns_pkt_set_tc.3 ldns_pkt_set_tsig.3 \
	ldns_pkt_size.3 ldns_pkt_tc.3 ldns_pkt_tsig.3 \
	ldns_pkt_tsig_sign.3 ldns_pkt_tsig_verify.3 ldns_pkt_type.3 \
	ldns_pkt_verify.3 ldns_pktheader2buffer_str.3 ldns_rdf.3 \
	ldns_rdf2buffer_str.3 ldns_rdf2buffer_str_a.3 \
	ldns_rdf2buffer_str_aaaa.3 ldns_rdf2buffer_str_alg.3 \
	ldns_rdf2buffer_str_apl.3 ldns_rdf2buffer_str_b64.3 \
	ldns_rdf2buffer_str_class.3 ldns_rdf2buffer_str_hex.3 \
	ldns_rdf2buffer_str_int16.3 ldns_rdf2buffer_str_int16_data.3 \
	ldns_rdf2buffer_str_ipseckey.3 ldns_rdf2buffer_str_loc.3 \
	ldns_rdf2buffer_str_nsap.3 ldns_rdf2buffer_str_nsec.3 \
	ldns_rdf2buffer_str_period.3 ldns_rdf2buffer_str_str.3 \
	ldns_rdf2buffer_str_tsigtime.3 ldns_rdf2buffer_str_type.3 \
	ldns_rdf2buffer_str_unknown.3 ldns_rdf2buffer_str_wks.3 \
	ldns_rdf2buffer_wire.3 ldns_rdf2native_int16.3 \
	ldns_rdf2native_int32.3 ldns_rdf2native_int8.3 \
	ldns_rdf2native_sockaddr_storage.3 ldns_rdf2native_time_t.3 \
	ldns_rdf2str.3 ldns_rdf2wire.3 ldns_rdf_address_reverse.3 \
	ldns_rdf_clone.3 ldns_rdf_compare.3 ldns_rdf_data.3 \
	ldns_rdf_deep_free.3 ldns_rdf_free.3 ldns_rdf_get_type.3 \
	ldns_rdf_new.3 ldns_rdf_new_frm_data.3 ldns_rdf_new_frm_fp.3 \
	ldns_rdf_new_frm_str.3 ldns_rdf_print.3 ldns_rdf_set_data.3 \
	ldns_rdf_set_size.3 ldns_rdf_set_type.3 ldns_rdf_size.3 \
	ldns_rdf_type.3 ldns_resolver_print.3 ldns_rr.3 \
	ldns_rr2buffer_str.3 ldns_rr2buffer_wire.3 ldns_rr2canonical.3 \
	ldns_rr2str.3 ldns_rr2wire.3 ldns_rr_class.3 ldns_rr_compare.3 \
	ldns_rr_compare_ds.3 ldns_rr_compress.3 ldns_rr_descript.3 \
	ldns_rr_descriptor.3 ldns_rr_descriptor_field_type.3 \
	ldns_rr_descriptor_maximum.3 ldns_rr_descriptor_minimum.3 \
	ldns_rr_dnskey_algorithm.3 ldns_rr_dnskey_flags.3 \
	ldns_rr_dnskey_key.3 ldns_rr_dnskey_protocol.3 \
	ldns_rr_dnskey_set_algorithm.3 ldns_rr_dnskey_set_flags.3 \
	ldns_rr_dnskey_set_key.3 ldns_rr_dnskey_set_protocol.3 \
	ldns_rr_free.3 ldns_rr_get_class.3 ldns_rr_label_count.3 \
	ldns_rr_list.3 ldns_rr_list2buffer_str.3 ldns_rr_list2str.3 \
	ldns_rr_list_cat.3 ldns_rr_list_clone.3 ldns_rr_list_free.3 \
	ldns_rr_list_new.3 ldns_rr_list_pop_rr.3 ldns_rr_list_print.3 \
	ldns_rr_list_push_rr.3 ldns_rr_list_rr_count.3 \
	ldns_rr_list_set_rr_count.3 ldns_rr_list_sort.3 \
	ldns_rr_mx_exchange.3 ldns_rr_mx_preference.3 ldns_rr_new.3 \
	ldns_rr_new_frm_fp.3 ldns_rr_new_frm_str.3 ldns_rr_new_frm_type.3 \
	ldns_rr_ns_nsdname.3 ldns_rr_owner.3 ldns_rr_pop_rdf.3 \
	ldns_rr_print.3 ldns_rr_push_rdf.3 ldns_rr_rd_count.3 \
	ldns_rr_rdata2buffer_wire.3 ldns_rr_rdf.3 \
	ldns_rr_rrsig_algorithm.3 ldns_rr_rrsig_expiration.3 \
	ldns_rr_rrsig_inception.3 ldns_rr_rrsig_keytag.3 \
	ldns_rr_rrsig_labels.3 ldns_rr_rrsig_origttl.3 \
	ldns_rr_rrsig_set_algorithm.3 ldns_rr_rrsig_set_expiration.3 \
	ldns_rr_rrsig_set_inception.3 ldns_rr_rrsig_set_keytag.3 \
	ldns_rr_rrsig_set_labels.3 ldns_rr_rrsig_set_origttl.3 \
	ldns_rr_rrsig_set_sig.3 ldns_rr_rrsig_set_signame.3 \
	ldns_rr_rrsig_set_typecovered.3 ldns_rr_rrsig_sig.3 \
	ldns_rr_rrsig_signame.3 ldns_rr_rrsig_typecovered.3 \
	ldns_rr_set_class.3 ldns_rr_set_owner.3 ldns_rr_set_pop_rr.3 \
	ldns_rr_set_push_rr.3 ldns_rr_set_rd_count.3 ldns_rr_set_rdf.3 \
	ldns_rr_set_ttl.3 ldns_rr_set_type.3 ldns_rr_ttl.3 ldns_rr_type.3 \
	ldns_rr_uncompressed_size.3 ldns_rrsig2buffer_wire.3 ldns_send.3 \
	ldns_sign_public.3 ldns_sign_public_dsa.3 \
	ldns_sign_public_rsamd5.3 ldns_sign_public_rsasha1.3 \
	ldns_status.3 ldns_str2period.3 ldns_str_remove_comment.3 \
	ldns_tcp_connect.3 ldns_tcp_read_wire.3 ldns_tcp_send_query.3 \
	ldns_update_adcount.3 ldns_update_pkt_new.3 \
	ldns_update_pkt_tsig_add.3 ldns_update_prcount.3 \
	ldns_update_set_adcount.3 ldns_update_set_prcount.3 \
	ldns_update_set_upcount.3 ldns_update_set_zocount.3 \
	ldns_update_upcount.3 ldns_update_zocount.3 ldns_verify.3 \
	ldns_verify_notime.3 ldns_verify_rrsig.3 ldns_verify_rrsig_dsa.3 \
	ldns_verify_rrsig_keylist.3 ldns_verify_rrsig_keylist_notime.3 \
	ldns_verify_rrsig_rsamd5.3 ldns_verify_rrsig_rsasha1.3 \
	ldns_wire2dname.3 ldns_wire2pkt.3 ldns_wire2rdf.3 ldns_wire2rr.3 \
	ldns_zone.3 ldns_zone_deep_free.3 ldns_zone_glue_rr_list.3 \
	ldns_zone_new.3 ldns_zone_new_frm_fp.3 ldns_zone_new_frm_fp_l.3 \
	ldns_zone_print.3 ldns_zone_push_rr.3 ldns_zone_push_rr_list.3 \
	ldns_zone_rr_count.3 ldns_zone_rrs.3 ldns_zone_set_rrs.3 \
	ldns_zone_set_soa.3 ldns_zone_soa.3 ldns_zone_sort.3
.endif

.if defined(WITH_EXAMPLES)
PLIST_SUB+=		EXAMPLES=""
NOMANCOMPRESS=	true
MANCOMPRESSED=	no
MAN1=	ldns-chaos.1 ldns-compare-zones.1 ldns-dpa.1 ldns-key2ds.1 \
	ldns-keyfetcher.1 ldns-keygen.1 ldns-mx.1 ldns-notify.1 \
	ldns-nsec3-hash.1 ldns-read-zone.1 ldns-resolver.1 ldns-revoke.1 \
	ldns-rrsig.1 ldns-signzone.1 ldns-testns.1 ldns-update.1 \
	ldns-verify-zone.1 ldns-version.1 ldns-walk.1 ldns-zcat.1 \
	ldns-zsplit.1 ldnsd.1
post-configure:
	@(cd ${WRKSRC}/examples; ./configure --prefix=${PREFIX} \
		--infodir=${PREFIX}/${INFO_PATH} --mandir=${MANPREFIX}/man \
		--build=${CONFIGURE_TARGET})

post-build:
	@(cd ${WRKSRC}/examples; ${GMAKE})

post-install:
	@(cd ${WRKSRC}/examples; ${GMAKE} install)
.else
PLIST_SUB+=		EXAMPLES="@comment "
.endif

.if ${OSVERSION} < 700000
CONFIGURE_ARGS+=	"--disable-sha2"
.endif

.include <bsd.port.post.mk>
