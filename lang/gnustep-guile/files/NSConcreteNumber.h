/* NSConcreteNumber - Interface for Concrete NSNumber classes
    
   Copyright (C) 1993,1994 Free Software Foundation, Inc.

   Written by:  Adam Fedor <fedor@boulder.colorado.edu>
   Date: Mar 1995

   This file is part of the GNUstep Base Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.
*/

#include <Foundation/NSValue.h>

@interface NSBoolNumber : NSNumber
{
  BOOL	data;
}
@end

@interface NSUCharNumber : NSNumber
{
  unsigned char	data;
}
@end

@interface NSCharNumber : NSNumber
{
  signed char	data;
}
@end

@interface NSUShortNumber : NSNumber
{
  unsigned short	data;
}
@end

@interface NSShortNumber : NSNumber
{
  signed short	data;
}
@end

@interface NSUIntNumber : NSNumber
{
  unsigned int	data;
}
@end

@interface NSIntNumber : NSNumber
{
  signed int	data;
}
@end

@interface NSULongNumber : NSNumber
{
  unsigned long	data;
}
@end

@interface NSLongNumber : NSNumber
{
  signed long	data;
}
@end

@interface NSULongLongNumber : NSNumber
{
  unsigned long long	data;
}
@end

@interface NSLongLongNumber : NSNumber
{
  signed long long	data;
}
@end

@interface NSFloatNumber : NSNumber
{
  float	data;
}
@end

@interface NSDoubleNumber : NSNumber
{
  double	data;
}
@end

