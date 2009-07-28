# New ports collection makefile for:	py-visual
# Date created:		2005-07-13
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	visual
PORTVERSION=	4.b26
#PORTREVISION=	0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	visualpython
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A python module that offers real 3D visual output

BUILD_DEPENDS=	${PYNUMPY} \
		bjam:${PORTSDIR}/devel/boost-jam
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea \
		gtkglextmm-x11-1.2:${PORTSDIR}/x11-toolkits/gtkglextmm \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		boost_python.4:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_PYTHON=	2.3+

OPTIONS=	EXAMPLES "install example files" on
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} --disable-dependency-tracking
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif
CONFIGURE_ENV=	PYTHONPATH=${PYTHON_LIBDIR}
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV=	LDFLAGS="${LDFLAGS} ${PTREAD_LIBS}"

VPYTHON_SCRIPT=	bin/vpython.in

.include <bsd.port.pre.mk>

.if !defined(WITH_EXAMPLES)
CONFIGURE_ARGS+=	--disable-examples
PLIST_SUB+=	PORTEXAMPLES="@comment "
.else
CONFIGURE_ARGS+=	--with-example-dir=${EXAMPLESDIR}
PLIST_SUB+=	PORTEXAMPLES=""
.endif

post-patch:
	@cd ${WRKSRC}; \
	${REINPLACE_CMD} -e 's|%%PYTHONBASE%%|${PYTHONBASE}|g' \
		-e 's|%%PYTHON_VERSION%%|${PYTHON_VER}|g' \
		${VPYTHON_SCRIPT}

.include <bsd.port.post.mk>
