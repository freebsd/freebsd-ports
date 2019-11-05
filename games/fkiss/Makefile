# Created by: Seiichirou Hiraoka <flathill@flathill.gr.jp>
# $FreeBSD$

PORTNAME=	fkiss
PORTVERSION=	0.33a
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www2s.biglobe.ne.jp/~yav/soft/fkiss/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/a//}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-patch${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freely enjoy childlike KISS, French-KISS!

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	lha:archivers/lha

BROKEN_aarch64=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list
BROKEN_armv6=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list
BROKEN_armv7=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list

EXTRA_PATCHES=	${WRKDIR}/${PORTNAME}-${PORTVERSION}.diff

USES=		gmake xorg
USE_XORG=	x11 xorgproto
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

PLIST_FILES=	bin/fkiss man/man1/fkiss.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|= @X_LIBS@|= @LDFLAGS@ @X_LIBS@|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g' \
		${WRKSRC}/sound.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fkiss ${STAGEDIR}${PREFIX}/bin/fkiss
	${INSTALL_MAN} ${WRKSRC}/fkiss.man \
		${STAGEDIR}${MANPREFIX}/man/man1/fkiss.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.euc \
		${STAGEDIR}${DOCSDIR}/README.ja_JP.eucJP

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/frkismi4.lzh \
		${STAGEDIR}${EXAMPLESDIR}/frkismi4.lzh

.include <bsd.port.mk>
