# New ports collection makefile for:	rhtvision
# Date created:		18 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	rhtvision
PORTVERSION=	1.1.4
PORTREVISION=	2
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

PATCHPERL_FILES=config.pl confignt.pl conflib.pl linux/compress \
		linuxso/makemak.in linuxso/makemak.pl

post-patch:
.for f in ${PATCHPERL_FILES}
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL5},g' ${WRKSRC}/${f}
.endfor

post-install:
	@cd ${PREFIX}/lib && ${LN} -sf librhtv.so.1.1.4 librhtv.so.1

.include <bsd.port.mk>
