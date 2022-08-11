PORTNAME=	intercal
PORTVERSION=	0.31
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	fuz@fuz.su
COMMENT=	C-INTERCAL compiler, ick, and supporting libraries

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes
CFLAGS+=	-D_POSIX_C_SOURCE=200809L
DATADIR=	${PREFIX}/share/ick

INFO=		ick

post-patch:
	@${REINPLACE_CMD} -e '/ICK_SPECIFIC_SUBDIR/s/-@PACKAGE_VERSION@// ' \
		${WRKSRC}/buildaux/Makefile.in

.include <bsd.port.mk>
