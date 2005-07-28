# New ports collection makefile for:	automake18
# Date created:		15 Feb 2003
# Whom:			Udo Schweigert
#
# $FreeBSD$
#

PORTNAME=	automake
PORTVERSION=	1.9.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
PKGNAMEPREFIX=	gnu-
DISTNAME=	automake-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator (GNU unmodified)

BUILD_DEPENDS=	${LOCALBASE}/gnu-autotools/bin/autoconf:${PORTSDIR}/devel/gnu-autoconf
RUN_DEPENDS=	${LOCALBASE}/gnu-autotools/bin/autoconf:${PORTSDIR}/devel/gnu-autoconf

PREFIX?=	${LOCALBASE}/gnu-autotools

USE_BZIP2=	yes
INFO=		automake
USE_PERL5=	yes
GNU_CONFIGURE=	yes
NO_MTREE=	yes
CONFIGURE_ENV=	AUTOCONF=${LOCALBASE}/gnu-autotools/bin/autoconf \
		AUTOHEADER=${LOCALBASE}/gnu-autotools/bin/autoheader \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--infodir=${PREFIX}/info

post-patch:
	@(cd ${WRKSRC}/doc && ${RM} -f *.info*)

.include <bsd.port.mk>
