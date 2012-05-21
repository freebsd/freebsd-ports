# New ports collection makefile for: 	fhist
# Date created:				Jan 05 2000
# Whom: 				<jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	fhist
PORTVERSION=	1.19
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities to maintain file history, do file comparisions and merges

LICENSE=	GPLv3

LIB_DEPENDS=	explain.45:${PORTSDIR}/devel/libexplain

OPTIONS=	NLS "Native language support" on

GNU_CONFIGURE=	yes
ALL_TARGET=	all-bin
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		fcomp.1 fhist.1 fmerge.1
PLIST_FILES=	bin/fcomp bin/fhist bin/fmerge

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ENV+=	ac_cv_lib_intl_main=no
.else
USE_GETTEXT=	yes
.for file in fcomp fhist fmerge
PLIST_FILES+=	share/locale/en/LC_MESSAGES/${file}.mo
.endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|.a $$(LIBS)|.a $$(LDFLAGS) $$(LIBS)|' ${WRKSRC}/Makefile.in

post-build:
.for file in fcomp fhist fmerge
.if !defined(WITHOUT_NLS)
	@(cd ${WRKSRC}/lib/en/LC_MESSAGES && ${LOCALBASE}/bin/msgfmt -o \
		${file}.mo ${file}.po)
.endif
.endfor

do-install:
.for file in fcomp fhist fmerge
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lib/en/man1/${file}.1 ${MANPREFIX}/man/man1
.if !defined(WITHOUT_NLS)
	@${MKDIR} ${PREFIX}/share/locale/en/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/lib/en/LC_MESSAGES/${file}.mo \
		${PREFIX}/share/locale/en/LC_MESSAGES
.endif
.endfor

.include <bsd.port.mk>
