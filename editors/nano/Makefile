# New ports collection makefile for:	nano
# Date created:				12 June 2000
# Whom:				Philippe Lefebvre <nemesis@balistik.net>
#
# $FreeBSD$
#

PORTNAME=	nano
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v2.2/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@eitanadler.com
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv3

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
MANLANG=	"" fr
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(NOPORTDOCS)
MAKE_ARGS+=	install_htmlmanDATA=install-htmlmanDATA
.else
MAKE_ARGS+=	install_htmlmanDATA=""
.endif

INFO=		nano
MAN1=		nano.1 rnano.1
MAN5=		nanorc.5

.include <bsd.port.pre.mk>

# requires wide character curses
.if (${OSVERSION} < 602107) || (${OSVERSION} >= 700000 && ${OSVERSION} < 700033)
CONFIGURE_ARGS+=--disable-utf8
.else
CONFIGURE_ARGS+=--enable-utf8
.endif

post-build:
	cd ${WRKSRC}/doc/man; ${REINPLACE_CMD} \
		-e 's:SYSCONFDIR:${PREFIX}/etc:g' \
		-e 's:EXAMPLESDIR:${EXAMPLESDIR}:g' \
		${MAN1} ${MAN5} ${WRKSRC}/doc/texinfo/${INFO:=.info}
	${REINPLACE_CMD} -e 's/\\</[[:<:]]/g' -e 's/\\>/[[:>:]]/g' \
		${WRKSRC}/doc/syntax/*.nanorc

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/nanorc.sample ${EXAMPLESDIR}

.include <bsd.port.post.mk>
