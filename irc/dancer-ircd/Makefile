# New ports collection makefile for:	dancer-ircd
# Date Created:		14 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dancer-ircd
PORTVERSION=	1.0.35
PORTREVISION=	1
CATEGORIES=	irc
#CATEGORIES=	irc ipv6
MASTER_SITES=	http://source.freenode.net/~asuffield/dancer/%SUBDIR%/ \
		http://source.freenode.net/~asuffield/dancer/%SUBDIR%/:doc1 \
		http://source.freenode.net/~asuffield/dancer/%SUBDIR%/:doc2
MASTER_SITE_SUBDIR=	${PORTNAME}/stable/releases \
			dancer-oper-guide:doc1 \
			dancer-user-guide:doc2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		dancer-oper-guide.txt:doc1 \
		dancer-user-guide.txt:doc2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An irc daemon based on hybrid ircd

IGNOREFILES=	dancer-oper-guide.txt \
		dancer-user-guide.txt

USE_RC_SUBR=	yes

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} 's:@@prefix@@:${PREFIX}:g' ${WRKSRC}/src/paths.c

post-build:
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' -e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		${FILESDIR}/dancer-ircd.sh > ${WRKDIR}/dancer-ircd.sh

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL} -d -m 700 -o ircd -g ircd \
		${PREFIX}/etc/dancer-ircd \
		/var/log/dancer-ircd \
		/var/run/dancer-ircd
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${PREFIX}/etc/dancer-ircd/ircd.conf.sample
.for f in kline.conf dline.conf motd ohelp omotd
	${TOUCH} ${PREFIX}/etc/dancer-ircd/${f}.sample
.endfor
.for f in ircd.conf kline.conf dline.conf motd ohelp omotd
	if [ ! -f ${PREFIX}/etc/dancer-ircd/${f} ]; then \
		${CP} ${PREFIX}/etc/dancer-ircd/${f}.sample ${PREFIX}/etc/dancer-ircd/${f}; \
	fi
.endfor
	${FIND} ${PREFIX}/etc/dancer-ircd -type d -print0 | \
		${XARGS} -0 ${CHMOD} 700
	${FIND} ${PREFIX}/etc/dancer-ircd -type f -print0 | \
		${XARGS} -0 ${CHMOD} 600
	${CHOWN} -R ircd:ircd ${PREFIX}/etc/dancer-ircd
	${INSTALL_SCRIPT} ${WRKDIR}/dancer-ircd.sh ${PREFIX}/etc/rc.d/
	${SED} -e "s,/usr/local/,${PREFIX}/,g" ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		 ${DISTDIR}/${DIST_SUBDIR}/dancer-oper-guide.txt \
		 ${DISTDIR}/${DIST_SUBDIR}/dancer-user-guide.txt \
		 ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
