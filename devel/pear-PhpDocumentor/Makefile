# Created by: Gerrit Beine (<gerrit.beine@gmx.de>)
# $FreeBSD$

PORTNAME=	PhpDocumentor
PORTVERSION=	1.4.4
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides automatic documenting of php-api from the source

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	pear-PHPDoc-[0-9]*

LATEST_LINK=	pear-${PORTNAME}
OPTIONS_DEFINE=	XML_BEAUTIFIER
XML_BEAUTIFIER_DESC=	XML_Beautifier support

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

.if ${PORT_OPTIONS:MXML_BEAUTIFIER}
RUN_DEPENDS+=	${PEARDIR}/XML/Beautifier.php:${PORTSDIR}/textproc/pear-XML_Beautifier
.endif

post-patch:
.for file in ${SUBFILES}
	@${REINPLACE_CMD} -e 's|@VER@|${PORTVERSION}|g ; \
		 s|@PEAR-DIR@|${PEARDIR}|g ; \
		 s|@DATA-DIR@|${DATADIR:S,/${PORTNAME}$,,}|g ; \
		 s|@WEB-DIR@|${DATADIR:S,/${PORTNAME}$,,}|g ; \
		 s|@DOC-DIR@|${DOCSDIR:S,/${PORTNAME}$,,}|g' ${WRKSRC}/${file}
.endfor

post-extract:
.for dir in ${DUMMYDIRS}
	${TOUCH} ${WRKSRC}/${dir}/.peardummy
.endfor

.include <bsd.port.post.mk>
