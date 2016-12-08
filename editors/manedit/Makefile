# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	manedit
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://wolfsinger.com/~wolfpack/packages/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	UNIX manual page editor and viewer

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAKEFILE=	Makefile.FreeBSD
USES=		alias tar:bzip2
USE_GNOME=	gtk12

MAKE_ARGS=	STAGEDIR="${STAGEDIR}"

pre-configure:
	@${CP} ${FILESDIR}/mntent* ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/-o $$(BIN)/s/(CC)/(CXX)/' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e '/^MAN/s/.bz2//' \
		-e 's/(PREFIX)/(STAGEDIR)$$&/' \
		-e '/@echo/s/^/#/' \
		-e 's/-o root -g wheel//' \
		${WRKSRC}/Makefile.install.FreeBSD
	@${REINPLACE_CMD} -e '/^SRC_C =/s//& mntent_compat.c/' \
		${WRKSRC}/Makefile.srclist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/manedit

.include <bsd.port.mk>
