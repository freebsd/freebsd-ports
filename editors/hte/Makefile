# ex:ts=8
# New ports collection makefile for:	HT Editor
# Date created:			Jun 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hte
PORTVERSION=	2.0.20
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/ht-source
DISTNAME=	ht-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A file editor/viewer/analyzer for executables

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ht

OPTIONS=	LZO2	"Enable external lzo2 compresssion support"	off	\
		X11	"Build X11 textmode support"			on

NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON=	does not build on ia64

.include <bsd.port.options.mk>

.if defined(WITH_LZO2)
LIB_DEPENDS+=	lzo2.2:${PORTSDIR}/archivers/lzo2
.else
CONFIGURE_ARGS=	--with-included-lzo
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=--disable-x11-textmode
.else
USE_XORG=	x11
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README
INFO=		ht
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS=.*$$|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|^CFLAGS=.*$$|CFLAGS="$$CFLAGS"|g ; \
		 s|-L/usr/X11/lib -L/usr/X11R6/lib|$$LDFLAGS|g' \
			${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ht ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/hthelp.info ${PREFIX}/${INFO_PATH}/ht.info
.endif

.include <bsd.port.mk>
