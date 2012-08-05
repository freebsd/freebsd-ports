# New ports collection makefile for: 	fhist
# Date created:				Jan 05 2000
# Whom: 				<jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	fhist
PORTVERSION=	1.21
DISTVERSIONSUFFIX=	.D001
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities to maintain file history, do file comparisons, and merges

LICENSE=	GPLv3

LIB_DEPENDS=	explain.45:${PORTSDIR}/devel/libexplain

OPTIONS_DEFINE=	NLS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-nlsdir=${PREFIX}/share/locale/en/LC_MESSAGES
ALL_TARGET=	all-bin
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		fcomp.1 fhist.1 fmerge.1
PLIST_FILES=	bin/fcomp bin/fhist bin/fmerge

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
.for file in fcomp fhist fmerge
PLIST_FILES+=	share/locale/en/LC_MESSAGES/${file}.mo
.endfor
.else
CONFIGURE_ENV+=	ac_cv_lib_intl_main=no
.endif

post-build:
.for file in fcomp fhist fmerge
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/lib/en/LC_MESSAGES && ${LOCALBASE}/bin/msgfmt -o \
		${file}.mo ${file}.po)
.endif
.endfor

do-install:
.for file in fcomp fhist fmerge
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lib/en/man1/${file}.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${PREFIX}/share/locale/en/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/lib/en/LC_MESSAGES/${file}.mo \
		${PREFIX}/share/locale/en/LC_MESSAGES
.endif
.endfor

.include <bsd.port.mk>
