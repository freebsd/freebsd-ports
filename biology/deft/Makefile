# New ports collection makefile for:	DeFT
# Date created:				1999-01-11
# Whom:					Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	deft
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://www.dq.ufscar.br/download/chem/dft/
DISTNAME=	DeFT_${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp
COMMENT=	Density functional molecular orbital calculation

WRKSRC=		${WRKDIR}/${DISTNAME}/source
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not install on FreeBSD >= 5.x"
.endif

.if ${OSVERSION} >= 400005
# Using g77 is troublesome, then it is better to use f2c/cc.
BUILD_DEPENDS=	ftn77:${PORTSDIR}/lang/f77
.endif
.if defined(USEMPICH) && ${USEMPICH} == yes
BUILD_DEPENDS+=	mpif77:${PORTSDIR}/net/mpich
FFLAGS+=	-I/usr/local/mpich/include
FC=		/usr/local/mpich/bin/mpif77
LFLAGS+=	-L/usr/local/mpich/lib -lmpich
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"\
		${WRKDIR}/${DISTNAME}/examples/DeFT
.if !defined(USEMPICH)
	@echo "******************************"
	@echo "If you want to use MPI library, set 'USEMPICH=yes'."
	@echo "******************************"
.endif

post-configure:
	${CP} ${FILESDIR}/Makefile.deft ${WRKSRC}/Makefile
.if defined(USEMPICH) && ${USEMPICH} == yes
	${MV} ${WRKSRC}/mpi.f ${WRKSRC}/mpi.f.notuse
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DeFT.exec ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/examples/DeFT ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/DeFT
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/bases ${PREFIX}/share/DeFT/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/DeFT
	${MKDIR} ${PREFIX}/share/examples/DeFT
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README_Liability \
		${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/input.* \
		${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/install.* \
		${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/README \
		${PREFIX}/share/examples/DeFT
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/*.dft \
		${PREFIX}/share/examples/DeFT
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/*.out \
		${PREFIX}/share/examples/DeFT
.endif

.include <bsd.port.post.mk>
