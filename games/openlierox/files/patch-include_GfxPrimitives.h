Provide missing constructor.

./include/CMap.h:423:18: error: no matching constructor for initialization of 'SDLRect' (aka 'OLXRect<SDLRectBasic>')
                if(!r.clipWith(SDLRect(0, 0, Width, Height)))
                               ^       ~~~~~~~~~~~~~~~~~~~
./include/GfxPrimitives.h:161:2: note: candidate constructor not viable: requires single argument 'r', but 4 arguments were provided
        OLXRect(const _RectBasic & r): _RectBasic(r) {}
        ^
--- include/GfxPrimitives.h.orig	2017-07-26 12:33:41 UTC
+++ include/GfxPrimitives.h
@@ -106,6 +106,12 @@ class SDLRectBasic : public SDL_Rect { (public)
 	typedef Uint16 TypeS;
 	
 	SDLRectBasic() { this->SDL_Rect::x = this->SDL_Rect::y = this->SDL_Rect::w = this->SDL_Rect::h = 0; }
+	SDLRectBasic(Type x_, Type y_, TypeS w_, TypeS h_) {
+		this->SDL_Rect::x = x_;
+		this->SDL_Rect::y = y_;
+		this->SDL_Rect::w = w_;
+		this->SDL_Rect::h = h_;
+	}
 	SDLRectBasic(const SDL_Rect & r): SDL_Rect(r) {}
 	Type& x() { return this->SDL_Rect::x; }
 	Type& y() { return this->SDL_Rect::y; }
@@ -158,6 +164,8 @@ template<typename _RectBasic>
 class OLXRect : public _RectBasic {
 public:
 
+	OLXRect(typename _RectBasic::Type x_, typename _RectBasic::Type y_,
+		typename _RectBasic::TypeS w_, typename _RectBasic::TypeS h_): _RectBasic(x_, y_, w_, h_) {}
 	OLXRect(const _RectBasic & r): _RectBasic(r) {}
 
 	class GetX2 {
