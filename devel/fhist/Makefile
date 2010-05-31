# New ports collection makefile for: 	fhist
# Date created:				Jan 05 2000
# Whom: 				<jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	fhist
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities to maintain file history, do file comparisions and merges

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	binaries po
MAKE_JOBS_UNSAFE=	yes

MAN1=		fcomp.1 fhist.1 fmerge.1
PLIST_FILES=	bin/fcomp bin/fhist bin/fmerge

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	ac_cv_lib_intl_main=no
.else
USE_GETTEXT=	yes
PLIST_FILES+=	share/locale/en/LC_MESSAGES/fcomp.mo \
		share/locale/en/LC_MESSAGES/fhist.mo \
		share/locale/en/LC_MESSAGES/fmerge.mo
.endif

post-extract:
	cd ${WRKSRC}/lib/en/man1 && ${LN} -s ${WRKSRC}/etc/*.so .

do-install:
.for file in fhist fcomp fmerge
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/bin/${file}
	(cd ${WRKSRC}/lib/en/man1; soelim ${file}.1 > tmp; \
	${INSTALL_MAN} tmp ${PREFIX}/man/man1/${file}.1)
.if !defined(WITHOUT_NLS)
	@${MKDIR} ${PREFIX}/share/locale/en/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/lib/en/LC_MESSAGES/${file}.mo \
		 ${PREFIX}/share/locale/en/LC_MESSAGES/${file}.mo
.endif
.endfor

.include <bsd.port.post.mk>
