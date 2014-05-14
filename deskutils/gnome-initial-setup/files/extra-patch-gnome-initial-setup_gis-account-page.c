$OpenBSD: patch-gnome-initial-setup_pages_account_gis-account-page_c,v 1.1 2014/04/26 17:08:12 ajacoutot Exp $

https://bugzilla.gnome.org/show_bug.cgi?id=728879
(upstream will _not_ accept --disable-kerberos patches)

--- gnome-initial-setup/pages/account/gis-account-page.c.orig	Mon Mar 10 05:47:29 2014
+++ gnome-initial-setup/pages/account/gis-account-page.c	Sat Apr 26 19:04:19 2014
@@ -41,7 +41,9 @@ typedef enum {
 struct _GisAccountPagePrivate
 {
   GtkWidget *page_local;
+#if 0
   GtkWidget *page_enterprise;
+#endif
 
   GtkWidget *page_toggle;
   GtkWidget *stack;
@@ -70,8 +72,10 @@ page_validate (GisAccountPage *page)
   switch (priv->mode) {
   case UM_LOCAL:
     return gis_account_page_local_validate (GIS_ACCOUNT_PAGE_LOCAL (priv->page_local));
+#if 0
   case UM_ENTERPRISE:
     return gis_account_page_enterprise_validate (GIS_ACCOUNT_PAGE_ENTERPRISE (priv->page_enterprise));
+#endif
   default:
     g_assert_not_reached ();
   }
@@ -102,7 +106,10 @@ set_mode (GisAccountPage *page,
 
   priv->mode = mode;
 
+#if 0
   visible_child = (mode == UM_LOCAL) ? priv->page_local : priv->page_enterprise;
+#endif
+  visible_child = priv->page_local;
   gtk_stack_set_visible_child (GTK_STACK (priv->stack), visible_child);
 
   update_page_validation (page);
@@ -126,9 +133,11 @@ gis_account_page_apply (GisPage *gis_page,
   switch (priv->mode) {
   case UM_LOCAL:
     return gis_account_page_local_apply (GIS_ACCOUNT_PAGE_LOCAL (priv->page_local), gis_page);
+#if 0
   case UM_ENTERPRISE:
     return gis_account_page_enterprise_apply (GIS_ACCOUNT_PAGE_ENTERPRISE (priv->page_enterprise), cancellable,
                                               enterprise_apply_complete, page);
+#endif
   default:
     g_assert_not_reached ();
     break;
@@ -180,14 +189,18 @@ gis_account_page_constructed (GObject *object)
   g_signal_connect (priv->page_local, "user-created",
                     G_CALLBACK (on_local_user_created), page);
 
+#if 0
   g_signal_connect (priv->page_enterprise, "validation-changed",
                     G_CALLBACK (on_validation_changed), page);
+#endif
 
   update_page_validation (page);
 
   g_signal_connect (priv->page_toggle, "toggled", G_CALLBACK (toggle_mode), page);
   g_object_bind_property (page, "applying", priv->page_toggle, "sensitive", G_BINDING_INVERT_BOOLEAN);
+#if 0
   g_object_bind_property (priv->page_enterprise, "visible", priv->page_toggle, "visible", G_BINDING_DEFAULT | G_BINDING_SYNC_CREATE);
+#endif
 
   /* force a refresh by setting to an invalid value */
   priv->mode = NUM_MODES;
@@ -211,7 +224,9 @@ gis_account_page_class_init (GisAccountPageClass *klas
   gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (klass), "/org/gnome/initial-setup/gis-account-page.ui");
 
   gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (klass), GisAccountPage, page_local);
+#if 0
   gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (klass), GisAccountPage, page_enterprise);
+#endif
 
   gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (klass), GisAccountPage, page_toggle);
   gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (klass), GisAccountPage, stack);
@@ -228,7 +243,9 @@ gis_account_page_init (GisAccountPage *page)
 {
   g_resources_register (account_get_resource ());
   g_type_ensure (GIS_TYPE_ACCOUNT_PAGE_LOCAL);
+#if 0
   g_type_ensure (GIS_TYPE_ACCOUNT_PAGE_ENTERPRISE);
+#endif
 
   gtk_widget_init_template (GTK_WIDGET (page));
 }
