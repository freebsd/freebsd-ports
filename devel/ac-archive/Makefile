# New ports collection makefile for: ac-archive
# Date Created:	10 December 2001
# Whom:		kerion
#
# $FreeBSD$
#

PORTNAME=	ac-archive
PORTVERSION=	0.5.65
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of useful GNU autoconf macros

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/acinclude
MAN1=		acinclude.1
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8 or newer to build. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
