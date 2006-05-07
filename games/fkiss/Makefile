# ports collection makefile for:	fkiss
# Date created:		31 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	fkiss
PORTVERSION=	0.33a
CATEGORIES=	games
MASTER_SITES=	http://www.oersted.co.jp/~yav/soft/fkiss/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/a//}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-patch${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freely enjoy childlike KISS, French-KISS!

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha

NOT_FOR_ARCHS=	alpha

USE_XLIB=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

MAN1=		fkiss.1
PLIST_FILES=	bin/fkiss %%EXAMPLESDIR%%/frkismi4.lzh
PLIST_DIRS=	%%EXAMPLESDIR%%

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CPPFLAGS+=	`pkg-config --cflags-only-I esound`
LDFLAGS+=	`pkg-config --libs-only-L esound `
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README README.ja_JP.eucJP
.endif

pre-patch:
	@cd ${WRKSRC} && ${CAT} ../${PORTNAME}-${PORTVERSION}.diff \
		| ${PATCH} ${PATCH_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's|= @X_LIBS@|= @LDFLAGS@ @X_LIBS@|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g' \
		${WRKSRC}/sound.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fkiss ${PREFIX}/bin/fkiss
	${INSTALL_MAN} ${WRKSRC}/fkiss.man ${MANPREFIX}/man/man1/fkiss.1
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/frkismi4.lzh ${EXAMPLESDIR}/frkismi4.lzh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/README.euc ${DOCSDIR}/README.ja_JP.eucJP
.endif

.include <bsd.port.post.mk>
