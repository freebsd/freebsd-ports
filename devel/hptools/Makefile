# New ports collection makefile for:	hp48tools
# Date created:		June 2003
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	hptools
PORTVERSION=	3.0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.hpcalc.org/hp48/pc/programming/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System RPL and assembly language tools for HP Calculators

WRKSRC=		${WRKDIR}/Hptools/${CONFIGURE_TARGET}

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../support/configure

NO_CDROM=	'Commercial use is Prohibited'

pre-patch:
	@${REINPLACE_CMD} -e 's,macintosh,__STDC__,'	\
		${WRKDIR}/Hptools/common/envfile.c	\
		${WRKDIR}/Hptools/rplcomp/defer.c	\
		${WRKDIR}/Hptools/rplcomp/masd.c
pre-configure:
	@(${MKDIR} ${WRKSRC})

post-install:
	@${STRIP_CMD}	${PREFIX}/bin/makerom ${PREFIX}/bin/rplcomp \
			${PREFIX}/bin/sasm ${PREFIX}/bin/sload
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/Hptools/doc/*.DOC ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/Hptools/doc/*.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
