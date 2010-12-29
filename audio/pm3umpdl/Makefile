# New ports collection makefile for: comiccron
# Date created:        5 February 2008
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	pm3umpdl
PORTVERSION=	1.0.0
CATEGORIES=	audio deskutils
MASTER_SITES=	http://cpan.org/authors/id/V/VV/VVELOX/
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Loading a M3U file into musicpd

RUN_DEPENDS=	${LOCALBASE}/bin/mpc:${PORTSDIR}/audio/mpc

USE_PERL5=	yes
NO_WRKSUBDIR=	yes

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} \
	--name=${PORTNAME} --center=${PORTNAME}" \
	user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	@${INSTALL_DATA} -v ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
