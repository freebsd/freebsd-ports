# Created by: <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fhist
PORTVERSION=	1.21
DISTVERSIONSUFFIX=	.D001
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities to maintain file history, do file comparisons, and merges

LICENSE=	GPLv3

LIB_DEPENDS=	libexplain.so:devel/libexplain

OPTIONS_DEFINE=	NLS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-nlsdir=${PREFIX}/share/locale/en/LC_MESSAGES
ALL_TARGET=	all-bin
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/fcomp bin/fhist bin/fmerge \
		man/man1/fcomp.1.gz man/man1/fhist.1.gz \
		man/man1/fmerge.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
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
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lib/en/man1/${file}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/en/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/lib/en/LC_MESSAGES/${file}.mo \
		${STAGEDIR}${PREFIX}/share/locale/en/LC_MESSAGES
.endif
.endfor

.include <bsd.port.mk>
