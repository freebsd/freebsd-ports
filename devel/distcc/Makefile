# New ports collection makefile for:	distcc
# Date created:				25 June 2002
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	distcc
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://distcc.samba.org/ftp/distcc/

MAINTAINER=	frerich.raabe@gmx.de

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,${PREFIX}/,,}
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-extra-includes="${LOCALBASE}/include" \
			--with-extra-libs="${LOCALBASE}/lib"

MAN1=	distcc.1 distccd.1
DOC_FILES=	AUTHORS COPYING COPYING.FDL NEWS OLDNEWS README \
		linuxdoc/distcc.info.gz linuxdoc/distcc.sgml
HTML_DOC_FILES=	distcc.html distcc-1.html distcc-2.html distcc-3.html \
		distcc-4.html distcc-5.html distcc-6.html distcc-7.html

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/distcc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/distccd ${PREFIX}/sbin

post-install: install-doc install-html-doc install-man
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

install-html-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
.for file in ${HTML_DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/linuxdoc/html/${file} ${DOCSDIR}/html
.endfor
.endif

install-man:
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
