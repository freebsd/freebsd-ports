# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	camomile
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/OldFiles
PKGNAMEPREFIX=	ocaml-
PKGNAMESUFFIX=	-examples
DISTNAME=	examples-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Example programs for Camomile library

WRKSRC=		${WRKDIR}/examples
NO_BUILD=	yes
USE_BZIP2=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -cf- -C ${WRKSRC} . | \
		${TAR} -xf- -C ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${EXAMPLESDIR} -exec ${CHOWN} ${SHAREOWN} {} \;

.include <bsd.port.mk>
