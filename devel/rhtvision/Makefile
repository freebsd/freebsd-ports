# New ports collection makefile for:	rhtvision
# Date created:		18 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	rhtvision
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tvision
DISTNAME=	rhtvision-${PORTVERSION}.src

MAINTAINER=	perky@FreeBSD.org

WRKSRC=		${WRKDIR}/tvision
USE_PERL5=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

post-patch:
.for f in config.pl confignt.pl conflib.pl linux/compress \
	linuxso/makemak.in linuxso/makemak.pl
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL5},g' \
		-e 's/\(soname.*\)intver/\1extver/g' \
		${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
