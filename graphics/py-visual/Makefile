# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	visual
PORTVERSION=	4.b26
PORTREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	SF/${PORTNAME}python/${PORTNAME}-module/VPython%204.beta26
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A python module that offers real 3D visual output

DEPRECATED=	Depends on the expired x11-toolkits/gtkglarea
EXPIRATION_DATE=	2013-02-06

BUILD_DEPENDS=	${PYNUMPY} \
		bjam:${PORTSDIR}/devel/boost-jam
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea \
		gtkglextmm-x11-1.2:${PORTSDIR}/x11-toolkits/gtkglextmm \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		boost_python.4:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_PYTHON=	2.5+

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} --disable-dependency-tracking
CONFIGURE_ENV=	PYTHONPATH=${PYTHON_LIBDIR}
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTREAD_LIBS}

VPYTHON_SCRIPT=	bin/vpython.in

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CONFIGURE_ARGS+=	--with-example-dir=${EXAMPLESDIR}
PLIST_SUB+=	PORTEXAMPLES=""
.else
CONFIGURE_ARGS+=	--disable-examples
PLIST_SUB+=	PORTEXAMPLES="@comment "
.endif

post-patch:
	@cd ${WRKSRC}; \
	${REINPLACE_CMD} -e 's|%%PYTHONBASE%%|${PYTHONBASE}|g' \
		-e 's|%%PYTHON_VERSION%%|${PYTHON_VER}|g' \
		${VPYTHON_SCRIPT}

.include <bsd.port.mk>
