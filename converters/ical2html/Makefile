PORTNAME=	ical2html
PORTVERSION=	3.0
CATEGORIES=	converters
MASTER_SITES=	http://www.w3.org/Tools/Ical2html/

MAINTAINER=	keiichi@iijlab.net
COMMENT=	Manipulation commands for iCalendar files
WWW=		https://www.w3.org/Tools/Ical2html/

LIB_DEPENDS=	libical.so:devel/libical

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/libical -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} '/icalerror_errors_are_fatal/d' \
		${WRKSRC}/ical2html.c \
		${WRKSRC}/icalfilter.c \
		${WRKSRC}/icalmerge.c

.include <bsd.port.mk>
