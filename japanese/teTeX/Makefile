# New ports collection makefile for:	teTeX
# Date created:		3 June 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	teTeX
PORTVERSION=	1.1
CATEGORIES=	japanese print
MASTER_SITES=	# empty
PKGNAMEPREFIX=	ja-
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A meta port for teTeX suite for Japanese (including pTeX and JTeX)

RUN_DEPENDS=	${TETEX_MODESW}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/share/texmf/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		tex:${PORTSDIR}/print/teTeX-base \
		ptex:${PORTSDIR}/japanese/ptex-tetex \
		dvips:${PORTSDIR}/japanese/dvipsk \
		xdvi:${PORTSDIR}/japanese/xdvik \
		jtex:${PORTSDIR}/japanese/texfamily \
		${JTEXVF}:${PORTSDIR}/japanese/texfamily-vfn2a

TETEX_MODESW=	${LOCALBASE}/bin/tetex-modesw
JTEXVF=		${LOCALBASE}/share/texmf-local/fonts/vf/n2a/dmjsy5.vf

PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PKGINSTALL_SUB=	TETEX_MODESW=${TETEX_MODESW} \
		MODE=${DEFAULT_MODE}

# XXX: We always build in batch mode to disable OPTIONS
#      in print/teTeX-base.
DEPENDS_ARGS+=	BATCH=yes

#OPTIONS=	LETTERSIZE "Use letter size by default" off

.include <bsd.port.pre.mk>

#.if defined(WITH_LETTERSIZE)
#FLAVOR+=	letter
#DEPENDS_ARGS+=	WITH_LETTERSIZE=true
#DEFAULT_MODE=	tetex-letter
#.else
DEFAULT_MODE=	ptex-tetex
#.endif

# XXX: this does not work
#.if defined(FLAVOR)
#PKGNAMESUFFIX=	${FLAVOR:S,^,-,:Q:S,\\ ,,g:S,\\-,-,g}
#.endif

do-configure:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}

do-build:
	@${DO_NADA}

do-install: #emtpy
	@${DO_NADA}

post-install:
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
