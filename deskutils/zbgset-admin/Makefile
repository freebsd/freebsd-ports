# New ports collection makefile for: zbgset-admin
# Date created:        24 June 2008
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	zbgset-admin
PORTVERSION=	0.0.1
CATEGORIES=	deskutils x11
MASTER_SITES=	http://cpan.org/authors/id/V/VV/VVELOX/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	This is a program for managing the ZConf stored settings for zbgset

RUN_DEPENDS=	${SITE_PERL}/Image/Size/FillFullSelect.pm:${PORTSDIR}/graphics/p5-Image-Size-FillFullSelect \
		${SITE_PERL}/ZConf.pm:${PORTSDIR}/devel/p5-ZConf

USE_PERL5=	yes
NO_WRKSUBDIR=	yes

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} --name=${PORTNAME} --center=${PORTNAME}" user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	@${CP} -v ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
	@${CP} -v ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/${PORTNAME}.1
	@${CHMOD} +x ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
