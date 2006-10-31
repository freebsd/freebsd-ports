# New ports collection makefile for: quilt
# Date created:        20 Oct 2006
# Whom:                Dirk Jagdmann <doj@cubic.org>
#
# $FreeBSD$
#

PORTNAME=	quilt
PORTVERSION=	0.46
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/quilt/

MAINTAINER=	doj@cubic.org
COMMENT=	A collection of bash scripts to ease working with patch files

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gsed:${PORTSDIR}/textproc/gsed \
		gpatch:${PORTSDIR}/devel/patch \
		diffstat:${PORTSDIR}/textproc/diffstat \
		rpm:${PORTSDIR}/archivers/rpm

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sed=${LOCALBASE}/bin/gsed --without-getopt --with-patch=${LOCALBASE}/bin/gpatch

MAN1=		guards.1 quilt.1
PORTDOCS=	README* quilt.pdf

post-install:
	@if [ ! -f ${PREFIX}/etc/quilt.quiltrc ]; then \
		${CP} ${PREFIX}/etc/quilt.quiltrc.sample \
			${PREFIX}/etc/quilt.quiltrc ; \
	fi

.include <bsd.port.mk>
