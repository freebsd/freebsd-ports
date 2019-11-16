commit ddd90b1502a263d03938b1e45a57684d576993ba
Author: Nils Philippsen <nils@redhat.com>
Date:   Fri Jul 31 16:25:58 2009 +0200

    patch: sane-backends-1.0.20
    
    Squashed commit of the following:
    
    commit 0c84326fa37bb309481c4d2658ab6cb17c9f0e85
    Author: Nils Philippsen <nils@redhat.com>
    Date:   Fri Jul 31 16:18:59 2009 +0200
    
        use SANE_CAP_ALWAYS_SETTABLE only if available

--- src/gtkglue.c.orig	2005-04-16 13:12:07 UTC
+++ src/gtkglue.c
@@ -1476,8 +1476,12 @@ gsg_set_sensitivity (GSGDialog * dialog, int sensitive
 	  || opt->type == SANE_TYPE_GROUP || !dialog->element[i].widget)
 	continue;
 
+#ifdef SANE_CAP_ALWAYS_SETTABLE
       if (!(opt->cap & SANE_CAP_ALWAYS_SETTABLE))
 	gtk_widget_set_sensitive (dialog->element[i].widget, sensitive);
+#else
+	gtk_widget_set_sensitive (dialog->element[i].widget, sensitive);
+#endif
     }
 }
 
