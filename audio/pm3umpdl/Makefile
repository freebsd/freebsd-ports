# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	pm3umpdl
PORTVERSION=	1.0.0
CATEGORIES=	audio deskutils
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Loading a M3U file into musicpd

RUN_DEPENDS=	${LOCALBASE}/bin/mpc:${PORTSDIR}/audio/musicpc

USES=		perl5
NO_STAGE=	yes
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
