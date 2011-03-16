# New ports collection makefile for:	hp48tools
# Date created:		June 2003
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	hptools
PORTVERSION=	3.0.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hpcalc.org/hp48/pc/programming/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System RPL and assembly language tools for HP Calculators

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/Hptools/${CONFIGURE_TARGET}

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../support/configure
PATCH_ARGS=	-E ${PATCH_STRIP}


NO_CDROM=	'Commercial use is Prohibited'

pre-patch:
	@${REINPLACE_CMD} -e 's,macintosh,__STDC__,'	\
		${WRKDIR}/Hptools/common/envfile.c	\
		${WRKDIR}/Hptools/rplcomp/defer.c	\
		${WRKDIR}/Hptools/rplcomp/masd.c
	cd ${WRKDIR}/Hptools && \
		${PATCH} ${PATCH_ARGS} < ${FILESDIR}/p-common_getopt.c
	cd ${WRKDIR}/Hptools && \
		${PATCH} ${PATCH_ARGS} < ${FILESDIR}/p-sload_symb.c

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
