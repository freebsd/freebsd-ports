# Created by: Seiichirou Hiraoka <flathill@flathill.gr.jp>
# $FreeBSD$

PORTNAME=	fkiss
PORTVERSION=	0.33a
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www2s.biglobe.ne.jp/~yav/soft/fkiss/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/a//}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-patch${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freely enjoy childlike KISS, French-KISS!

LICENSE=	GPLv2

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha

EXTRA_PATCHES=	${WRKDIR}/${PORTNAME}-${PORTVERSION}.diff

USES=		gmake
USE_XORG=	x11 xproto
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

PLIST_FILES=	bin/fkiss man/man1/fkiss.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

# XXX should be converted to OptionsNG
.if ${HAVE_GNOME:Mesound}
USES+=		pkgconfig
USE_GNOME+=	esound
CPPFLAGS+=	`pkg-config --cflags-only-I esound`
LDFLAGS+=	`pkg-config --libs-only-L esound `
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= @X_LIBS@|= @LDFLAGS@ @X_LIBS@|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g' \
		${WRKSRC}/sound.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fkiss ${STAGEDIR}${PREFIX}/bin/fkiss
	${INSTALL_MAN} ${WRKSRC}/fkiss.man \
		${STAGEDIR}${MANPREFIX}/man/man1/fkiss.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.euc \
		${STAGEDIR}${DOCSDIR}/README.ja_JP.eucJP
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/frkismi4.lzh \
		${STAGEDIR}${EXAMPLESDIR}/frkismi4.lzh

.include <bsd.port.post.mk>
