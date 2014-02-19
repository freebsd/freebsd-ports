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

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -cf- -C ${WRKSRC} . | \
		${TAR} -xf- -C ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -exec ${CHOWN} ${SHAREOWN} {} \;

.include <bsd.port.mk>
