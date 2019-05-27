#include "bitmap_image.hpp"

// creates the BMP image image.bmp that tests expect

int main()
{
   bitmap_image base(1024, 800);
   base.clear();

   const double c1 = 0.8;
   const double c2 = 0.4;
   const double c3 = 0.2;
   const double c4 = 0.6;

   ::srand(0xA5AA57A0);
   plasma(base, 0, 0, base.width(), base.height(), c1, c2, c3, c4, 3.0, jet_colormap);

   base.save_image("image.bmp");

   return 0;
}
