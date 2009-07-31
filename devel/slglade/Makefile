# New ports collection makefile for:	slglade
# Date created:		15 Aug 2008
# Whom:			Alexey Shuvaev <shuvaev@phyisik.uni-wuerzburg.de>
#
# $FreeBSD$
#

PORTNAME=	slglade
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://laurent.perez2.free.fr/comp/slang/modules/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shuvaev@physik.uni-wuerzburg.de
COMMENT=	S-Lang binding for libglade

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2
RUN_DEPENDS=	imdisplay:${PORTSDIR}/x11-toolkits/slgtk

USE_GNOME=	libglade2
GNU_CONFIGURE=	yes

post-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|doc/slglade|share/&|' ${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} -e 's/doc //' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.sl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.glade ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
