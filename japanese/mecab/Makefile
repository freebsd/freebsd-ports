# New ports collection makefile for:	mecab
# Date created:		2 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mecab
PORTVERSION=	0.94
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

USE_AUTOTOOLS=	libtool:15
USE_ICONV=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I ${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

# Default charset (euc-jp/shift_jis/utf-8)
.if defined(WITH_CHARSET)
CONFIGURE_ARGS+=	--with-charset=${WITH_CHARSET}
.endif

MAN1=		mecab.1

DOCS=		AUTHORS README doc/*.html

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.x or later.  Install lang/perl5.8 and try again
.endif

post-patch:
	${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' \
			 -e 's/-O3/${CFLAGS}/' ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's/conf_DATA = mecabrc/conf_DATA = mecabrc.dist/' ${WRKSRC}/Makefile.in

post-configure:
	${CP} ${WRKSRC}/mecabrc ${WRKSRC}/mecabrc.dist

post-install:
	@if [ ! -f ${TARGETDIR}/etc/mecabrc ]; then \
		${INSTALL_DATA} ${TARGETDIR}/etc/mecabrc.dist ${TARGETDIR}/etc/mecabrc; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
