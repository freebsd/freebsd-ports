PORTNAME=	virtual_oss_ctl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical control panel for the virtual OSS daemon
WWW=		https://github.com/hselasky/virtual_oss_ctl

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		compiler:c++11-lang gl qmake qt:5
USE_GL=		gl
USE_QT=		buildtools:build core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

PLIST_FILES= \
	bin/virtual_oss_ctl \
	share/pixmaps/virtual_oss_ctl.png \
	share/applications/virtual_oss_ctl.desktop

.include <bsd.port.pre.mk>

# From 1500066 onwards we have virtual_oss in base.
.if ${OSVERSION} >= 1500066
.if !exists(${SRC_BASE})
IGNORE=		requires FreeBSD source files in ${SRC_BASE}
.else
CXXFLAGS+=	-I${SRC_BASE}/usr.sbin/virtual_oss
.endif
.else
RUN_DEPENDS=	virtual_oss>=1.2.6:audio/virtual_oss
GH_TUPLE=	freebsd:virtual_oss:v1.3.2:d/virtual_oss
.endif

.include <bsd.port.post.mk>
