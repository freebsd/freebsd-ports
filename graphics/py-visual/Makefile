# New ports collection makefile for:	py-visual
# Date created:		2005-07-13
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	visual
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://www.vpython.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@email.it
COMMENT=	A python module that offers real 3D visual output

BUILD_DEPENDS=	${PYNUMERIC} \
		bjam:${PORTSDIR}/devel/boost-python
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
RUN_DEPENDS=	${PYNUMERIC}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=	15
USE_PYTHON=	2.3+
USE_REINPLACE=	yes
USE_XLIB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--with-example-dir=${EXAMPLESDIR}
CONFIGURE_ENV=	PYTHONPATH=${PYTHON_LIBDIR}
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif

VPYTHON_SCRIPT=	bin/vpython.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not compile"
.endif

post-patch:
	@cd ${WRKSRC}; \
	${REINPLACE_CMD} -e 's|%%PYTHONBASE%%|${PYTHONBASE}|g' \
		-e 's|%%PYTHON_VERSION%%|${PYTHON_VERSION:S/python//g}|g' \
		${VPYTHON_SCRIPT}

.include <bsd.port.post.mk>
