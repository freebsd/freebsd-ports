# New ports collection makefile for:		Boo
# Date created:					June 17, 2005
# Whom:				Christopher Nehren <apeiron@coitusmentis.info>
#
# $FreeBSD$
#

PORTNAME=	boo
PORTVERSION=	0.9.2
CATEGORIES=	lang
MASTER_SITES=	http://dist.codehaus.org/boo/distributions/
DISTNAME=	${PORTNAME}-${PORTVERSION}.${BUILD_NUMBER}-src

MAINTAINER=	mono@FreeBSD.org
COMMENT=	A CLI-targeted programming language similar to Python

PATCH_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info

WRKSRC=		${WRKDIR}
USE_GNOME=	gtksourceview
USE_NANT=	yes
USE_ZIP=	yes

BUILD_NUMBER=	3383

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's!%%PREFIX%%!${PREFIX}!' \
		-e 's!%%DOCSDIR%%!${DOCSDIR}!' \
		-e 's!%%EXAMPLESDIR%%!${EXAMPLESDIR}!' \
		${WRKSRC}/default.build
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/%%INSTALLDOCS%%//' ${WRKSRC}/default.build
.else
	@${REINPLACE_CMD} -e 's/%%INSTALLDOCS%%/install-docs,/' ${WRKSRC}/default.build
.endif
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e 's/%%INSTALLEXAMPLES%%//' ${WRKSRC}/default.build
.else
	@${REINPLACE_CMD} -e 's/%%INSTALLEXAMPLES%%/install-examples,/' ${WRKSRC}/default.build
.endif

post-install:
	${LOCALBASE}/bin/update-mime-database ${LOCALBASE}/share/mime

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
