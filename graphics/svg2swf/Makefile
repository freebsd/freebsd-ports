# ex:ts=8
# New ports collection makefile for:	svg2swf
# Date created:			24 August 2000
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	svg2swf
PORTVERSION=	0.1.3
CATEGORIES=	graphics python
MASTER_SITES=	http://www.eskimo.com/~robla/svg2swf/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert an SVG file into a Macromedia Flash (swf) file

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/${PACKAGE_DIR}/sax/saxexts.py:${PORTSDIR}/textproc/py-xml \
		${PYTHON_SITELIBDIR}/ming.py:${PORTSDIR}/graphics/py-ming

PLIST_FILES=	bin/svg2swf
USE_REINPLACE=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python1.5"
PACKAGE_DIR=	xml
.else
PACKAGE_DIR=	_xmlplus
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/python,${PYTHON_CMD},g" ${WRKSRC}/svg2swf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/svg2swf ${PREFIX}/bin

.include <bsd.port.post.mk>
