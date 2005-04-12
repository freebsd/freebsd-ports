# ex:ts=8
#
# New ports collection makefile for:	cyclone
# Date created:		2002/01/06
# Whom:			alane <alane@FreeBSD.org> et al
#
# $FreeBSD$
#

PORTNAME=	cyclone
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.cornell.edu/projects/cyclone/software/
# Can't conditionalise fetching of docs due to distinfo:
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-docs.tgz

MAINTAINER=	vs@FreeBSD.org
COMMENT=	A safe dialect of C from Cornell and AT&T Research

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S/^${PREFIX}\///} \
		PORTBLD=${MACHINE_ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=	all gprof aprof
CYCBINDIR=	${PREFIX}/bin
CYCINCDIR=	${PREFIX}/include/cyclone
CYCLIBDIR=	${PREFIX}/lib/cyclone

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=		"Cannot convert header files on -CURRENT!"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/online-manual
	@${INSTALL_DATA} ${WRKDIR}/*.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/online-manual/* ${DOCSDIR}/online-manual
.endif

.include <bsd.port.post.mk>
