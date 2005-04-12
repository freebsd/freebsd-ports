# New ports collection makefile for: ac-archive
# Date Created:	10 December 2001
# Whom:		kerion
#
# $FreeBSD$
#

PORTNAME=	ac-archive
PORTVERSION=	0.5.57
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of useful GNU autoconf macros

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	259
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/acinclude
MAN1=		acinclude.1
PORTDOCS=	*

.include <bsd.port.mk>
