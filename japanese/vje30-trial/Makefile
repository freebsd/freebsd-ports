# New ports collection makefile for:	VJE-Delta 3.0 Trial
# Date created:		14 January 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	vje
PORTVERSION=	3.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.vacs.co.jp/pub/unix/vje30/FreeBSD/	\
		http://www.green.machida.ne.jp/vacs/unix/FreeBSD/
PKGNAMESUFFIX=	-trial
DISTNAME=	${PORTNAME}-delta-${PORTVERSION}t-ELF
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	vje30

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Modern intelligent Japanese input engine (trial version)

LIB_DEPENDS=	c.3:${PORTSDIR}/misc/compat3x
#RUN_DEPENDS=	${LOCALBASE}/share/java/classes/jfc-1.1.1/swing.jar:${PORTSDIR}/java/jfc

NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386

PLIST_SUB=	BINSTUFF="${BINSTUFF}"

WRKSRC=		${WRKDIR}/usr/local

.include <bsd.port.pre.mk>

BINSTUFF=	vje	\
		vjed	\
		vadd	\
		vdel	\
		vdispd	\
		vmaked	\
		vpen	\
		vpu	\
		vjekill	\
		vpr	\
		vprc	\
		vjeacc

post-patch:
	@cd ${WRKSRC}/vje30/bin && ${RM} swingall.jar
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${CP} ${FILESDIR}/vje.sh ${WRKSRC}/etc/rc.d/
.if defined(NOPORTDOCS)
	@cd ${WRKSRC}/vje30 && ${RM} -rf doc README FAQ
.endif

do-install:
	@cd ${WRKSRC} && tar cf - . | tar xf - -C ${PREFIX}
.for f in ${BINSTUFF}
	@${LN} -fs ${PREFIX}/vje30/bin/$f ${PREFIX}/bin/$f
.endfor
	@${CHMOD} a+x ${PREFIX}/etc/rc.d/vje.sh
	@${CHMOD} a+w ${PREFIX}/vje30/dic/vjed95m.dic
	@[ X${PREFIX} = X"/usr/local" ] || (${LN} -s ${PREFIX}/vje30 /usr/local/; ${LN} -s ${PREFIX}/etc/vje30 /usr/local/etc/)
	@${CP} -Pp /etc/services /etc/services.bak
	@${GREP} -qw '^vjed' /etc/services || ${ECHO_CMD} "vjed		11493/tcp		# VJE-Delta Server" >> /etc/services

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
