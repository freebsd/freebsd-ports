# New ports collection makefile for:	silentbob
# Date created:		2008-11-13
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	silentbob
PORTVERSION=	1.7.6
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Yet another sourcecode indexing tool

USE_CMAKE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*
MAN1=		silent_bob.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/silent_bob/|${PREFIX}/lib/silent_bob/|' \
		${WRKSRC}/src/init.cxx

pre-configure:
	${CP} ${WRKSRC}/CMakeLists_bsd.txt ${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/silent_bob.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/silent_bob
	${INSTALL_PROGRAM} ${WRKSRC}/libplugin_*.so ${PREFIX}/lib/silent_bob
.for l in bob tags the_tt gc_indent bob_perl bob_python bob_ruby
	${LN} -s silent_bob ${PREFIX}/bin/${l}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
