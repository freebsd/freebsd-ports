# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	pm3umpdl
PORTVERSION=	1.0.0
CATEGORIES=	audio deskutils
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Loading a M3U file into musicpd

RUN_DEPENDS=	${LOCALBASE}/bin/mpc:audio/musicpc

USES=		perl5

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} \
	--name=${PORTNAME} --center=${PORTNAME}" \
	user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_DATA} -v ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
