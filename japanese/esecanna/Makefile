# New ports collection Makefile for: esecanna for VJE-Delta 3.0
# Version required:	0.2.2
# Date created:		29 January 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	esecanna-vje30_DR-0.2.2
PKGNAME=	ja-esecanna-vje30-0.2.2
CATEGORIES=	japanese
MASTER_SITES=	http://www.idaemons.org/ports/distfiles/ \
		http://plaza.harmonix.ne.jp/~redstar/

MAINTAINER=	knu@idaemons.org

#RUN_DEPENDS=	${LOCALBASE}/vje30/bin/vjed:${PORTSDIR}/japanese/vje30-trial

DOCDIR=		${PREFIX}/share/doc/esecanna

# Make sure of naming it proper so as to be invoked *after* vje.sh on startup
STARTER=	vjeesecannaserver.sh

post-extract:
	@perl -pe "s,!!PREFIX!!,${PREFIX},g" ${FILESDIR}/${STARTER} > ${WRKSRC}/${STARTER}

do-configure:
	@cd ${WRKSRC} && perl -i -pe " \
		s,/etc/esecannarc,${PREFIX}/etc/esecannarc,g; \
		s,/etc/vje30,${PREFIX}/etc/vje30,g; \
		s,/usr/lib/vje30,${PREFIX}/vje30,g; \
		s,/usr/sbin/vjed,${PREFIX}/vje30/bin/vjed,g; \
		" \
		4DEVELOPERS.jp \
		esecannarc \
		imewrapper.c \
		vjewrapper.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esecannaserver ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/esecannarc ${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/${STARTER} ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/4DEVELOPERS.jp ${WRKSRC}/README.jp ${DOCDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
