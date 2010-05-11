diff --git a/src/context/applets/info/InfoApplet.h b/src/context/applets/info/InfoApplet.h
index 4be28fc..775ea7c 100644
--- ./src/context/applets/info/InfoApplet.h
+++ ./src/context/applets/info/InfoApplet.h
@@ -48,6 +48,8 @@ public:
     InfoApplet( QObject* parent, const QVariantList& args );
     virtual ~InfoApplet();
 
+    void init();
+
     void paintInterface( QPainter *painter, const QStyleOptionGraphicsItem *option, const QRect &contentsRect );
     void constraintsEvent( Plasma::Constraints constraints = Plasma::AllConstraints );
 
