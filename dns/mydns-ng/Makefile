# New ports collection makefile for:	mydns
# Date created:				23 July 2002
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	mydns
PORTVERSION=	0.9.3
CATEGORIES=	net databases
MASTER_SITES=	http://mydns.bboy.net/download/

MAINTAINER=	simond@irrelevant.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-confdir=${PREFIX}/etc --without-libiconv-prefix
USE_BZIP2=	yes
USE_REINPLACE=	yes

MAN5=		mydns.conf.5
MAN8=		mydns.8 mydnscheck.8 mydnsexport.8 mydnsimport.8

DOCS=	AUTHORS COPYING ChangeLog NEWS QUICKSTART README TODO

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
USE_PERL5=	yes
.else
pre-configure:
	@${REINPLACE_CMD} -E -e "s|^(all: vars manpages info) html-doc|\1|" \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${SED} 's|%%%PREFIX%%%|${PREFIX}|g' < ${FILESDIR}/mydns.sh > ${WRKSRC}/mydns.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/mydns.sh ${PREFIX}/etc/rc.d/mydns.sh.sample
	@install-info ${PREFIX}/info/mydns.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}/html ${DOCSDIR}/contrib
.for f in ${DOCS}
	        @${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}/html/
	@${INSTALL_DATA} ${WRKSRC}/contrib/admin.php ${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/
.endif
	@${PREFIX}/sbin/mydns --dump-config >${PREFIX}/etc/mydns.conf.sample
	@${SED} -e 's,%%%PREFIX%%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
