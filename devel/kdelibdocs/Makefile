# New ports collection makefile for:   kdelibdocs
# Date created:        8 Feb 2000
# Whom:                imura@af.airnet.ne.jp
#
# $FreeBSD$
#

PORTNAME=	kdelibdocs
PORTVERSION=	1.1
CATEGORIES=	devel kde
MASTER_SITES=	ftp://129.187.206.68/pub/unix/ide/KDevelop/documentation/ \
		ftp://gd.tuwien.ac.at/hci/KDevelop/documentation/ \
		ftp://fara.cs.uni-potsdam.de/pub/kdevelop/documentation/

MAINTAINER=	ports@FreeBSD.org

USE_KDELIBS_VER=1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-qtdoc-dir=${X11BASE}/share/doc/qt/html"

.include <bsd.port.mk>
