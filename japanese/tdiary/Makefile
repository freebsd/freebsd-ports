# New ports collection makefile for:    tdiary
# Date created:                 21 May 2003
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	tdiary
PORTVERSION=	1.5.4
CATEGORIES=	japanese ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sourceforge/${PORTNAME}
DISTNAME=	${PORTNAME}-full-${PORTVERSION:R}.${PORTVERSION:E}

MAINTAINER=	jfkimura@yahoo.co.jp
COMMENT=	A Web-based diary system (like weblog) written in Ruby

.if defined(WITH_TDIARY_UCONV)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv
.endif
.if defined(WITH_TDIARY_NORA)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif

NO_BUILD=	yes
USE_RUBY=	yes

TDIARYDIR=	${PREFIX}/share/examples/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}.${PORTVERSION:E}

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${ECHO_MSG} "You may use the following options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITH_TDIARY_UCONV=yes	(with UTF-8 support : output_rdf.rb)"
	@${ECHO_MSG} "WITH_TDIARY_NORA=yes	(with Referer header support : disp_referrer.rb)"
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${ECHO_MSG}

do-install:
	@if [ -d ${TDIARYDIR} ]; then ${RM} -rf ${TDIARYDIR}; fi
	${MKDIR} ${TDIARYDIR}
	${SED} -e 's,@@@@PREFIX@@@@,${PREFIX},g' \
	${FILESDIR}/tdiary-FreeBSD.sh.in > ${TDIARYDIR}/tdiary-FreeBSD.sh
	${CHMOD} ugo=rx ${TDIARYDIR}/tdiary-FreeBSD.sh
	${CP} -pR ${WRKSRC}/ ${TDIARYDIR}
.if defined(WITH_TDIARY_UCONV)
	${INSTALL_DATA} ${WRKSRC}/misc/plugin/output_rdf.rb ${TDIARYDIR}/plugin
.endif
.if defined(WITH_TDIARY_NORA)
	${INSTALL_DATA} ${WRKSRC}/misc/plugin/disp_referrer.rb ${TDIARYDIR}/plugin
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TDIARYDIR}

post-install:
	@cd ${WRKSRC} && ${FIND} . -type f -o -type l | ${SED} 's,^\.,share/examples/${PORTNAME},' | sort >> ${TMPPLIST}
.if defined(WITH_TDIARY_UCONV)
	@cd ${WRKSRC} && ${ECHO} 'share/examples/${PORTNAME}/plugin/output_rdf.rb' >> ${TMPPLIST}
.endif
.if defined(WITH_TDIARY_NORA)
	@cd ${WRKSRC} && ${ECHO} 'share/examples/${PORTNAME}/plugin/disp_referrer.rb' >> ${TMPPLIST}
.endif
	@cd ${WRKSRC} && ${FIND} . -type d -depth | ${SED} 's,^\.,@dirrm share/examples/${PORTNAME},' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
