# New ports collection makefile for:	pure-ftpd
# Date created:				22 April 2001
# Whom:					Frank DENIS
#
# $FreeBSD$
#

PORTNAME=	pure-ftpd
PORTVERSION=	0.98.7
CATEGORIES=	ftp ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pureftpd

MAINTAINER=	j@4u.net

.if defined(WITH_DMALLOC)
LIB_DEPENDS+=	dmalloc.1:${PORTSDIR}/devel/dmalloc
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pam --with-cookie --with-throttling \
			--with-ratios --with-ftpwho --with-largefile \
			--with-uploadscript --with-virtualhosts
# language support requested?
.if defined(WITH_LANG)
CONFIGURE_ARGS+=	--with-language="${WITH_LANG}"
.endif
# use of dmalloc requested?
.if defined(WITH_DMALLOC)
CONFIGURE_ARGS+=	--with-dmalloc
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
.endif

MAN8=		pure-ftpd.8 pure-ftpwho.8 pure-mrtginfo.8 pure-uploadscript.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
PAM_TEMPL?=	${FILESDIR}/pam.conf.5
.else
. if ${OSVERSION} > 400000
PAM_TEMPL?=	${FILESDIR}/pam.conf.4
. endif
.endif
.if defined(PAM_TEMPL)
PAM_DIR?=	${PREFIX}/share/examples/${PORTNAME}/pam
PAM_TARGET?=	pure-ftpd
.endif

DOCS=		AUTHORS CONTACT COPYING HISTORY NEWS \
		README README.Configuration-File README.Contrib README.LDAP \
		README.Netfilter \
		THANKS

CONTRIB=	xml_python_processors.txt

pre-fetch:
	@${ECHO} "You can use the following additional options:"
	@${ECHO} "WITH_DMALLOC	- enable use of the dmalloc library;"
	@${ECHO} "WITH_LANG=lang	- enable compilation of language support, lang is one of"
	@${ECHO} "		  english, german, romanian, french, polish or spanish."

post-install:
	${INSTALL_DATA} ${WRKSRC}/pureftpd-ldap.conf ${PREFIX}/etc/pureftpd-ldap.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-ftpd.conf ${PREFIX}/etc/pure-ftpd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-config.pl ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/share/examples/pure-ftpd
	(cd ${WRKSRC}/contrib && ${INSTALL_SCRIPT} ${CONTRIB} ${PREFIX}/share/examples/pure-ftpd)
	${CHMOD} 755 ${PREFIX}/sbin/pure-config.pl
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pure-ftpd
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/pure-ftpd)
.endif
.if defined(PAM_TEMPL)
	${MKDIR} ${PAM_DIR}
	${INSTALL_DATA} ${PAM_TEMPL} ${PAM_DIR}/${PAM_TARGET}
	@${ECHO} "Now you need to examine ${PAM_DIR}/${PAM_TARGET}"
	@${ECHO} "and add the relevant PAM configuration lines to your /etc/pam.conf file."
.endif

.include <bsd.port.post.mk>
