# New ports collection makefile for:	icmake
# Date created:		March 4, 2009
# Whom:	      		Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icmake
PORTVERSION=	7.11.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rug.nl/contrib/frank/software/linux/icmake/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	An Intelligent C-like Maker

MANCOMPRESSED=	yes
MAN1=		icmake.1 icmbuild.1 icmstart.1

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	icmake.doc icmake.ps README.icmbuild

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr/bin"|"${PREFIX}/bin"| ; \
		s|"/usr/share/icmake"|"${PREFIX}/share/icmake-${PORTVERSION}"| ; \
		s|"/usr/share/man/man1"|"${PREFIX}/man/man1"| ; \
		s|"/usr/lib/icmake"|"${PREFIX}/lib/icmake-${PORTVERSION}"|' \
		${WRKSRC}/def/destinations

do-build:
	cd ${WRKSRC} && ${SH} ./bootstrap.sh

do-install:
	cd ${WRKSRC} && \
		${SH} ./install.sh strip && \
		./unix skel && \
		./unix man
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
