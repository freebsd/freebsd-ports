# New ports collection makefile for:	VJE-Delta 3.0
# Date created:		29 January 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	vje
PORTVERSION=	3.0
CATEGORIES=	japanese
MASTER_SITES=	file:${MOUNT_PT}/freebsd/
EXTRACT_SUFX=	.tgz
DISTNAME=	${PORTNAME}-delta-${PORTVERSION}-${DISTOBJFORMAT}

MAINTAINER=	knu@idaemons.org

#RUN_DEPENDS=	${LOCALBASE}/share/java/classes/jfc-1.1.1/swing.jar:${PORTSDIR}/java/jfc

NO_BUILD=	yes
RESTRICTED=	"You must purchase a licensed copy from VACS Corporation."
NO_CDROM=	"You must purchase a licensed copy from VACS Corporation."
NO_PACKAGE=	"You must purchase a licensed copy from VACS Corporation."

ONLY_FOR_ARCHS=	i386

PLIST_SUB=	BINSTUFF="${BINSTUFF}"

WRKSRC=		${WRKDIR}/usr/local

MOUNT_PT?=	/cdrom

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTOBJFORMAT=	AOUT
.else
DISTOBJFORMAT=	ELF
.endif

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

pre-fetch:
	@[ -d ${MOUNT_PT}/freebsd ] || ( \
	${ECHO} "*****************************************************************";	\
	${ECHO} "To install VJE-Delta 3.0, make sure your purchased CD-ROM is";		\
	${ECHO} "mounted on at ${MOUNT_PT} or an arbitrary mountpoint that can be";	\
	${ECHO} "specified by setting MOUNT_PT variable in a make command line.";	\
	${ECHO} "";									\
	${ECHO} "e.g.";									\
	${ECHO} "	mount /dev/cd0c /mnt/cdrom";					\
	${ECHO} "	make MOUNT_PT=/mnt/cdrom install";				\
	${ECHO} "*****************************************************************";	\
	${FALSE}									\
	)

post-extract:
	@${RM} ${DISTDIR}/${DISTFILES}

post-patch:
	@cd ${WRKSRC}/vje30/bin && ${RM} swingall.jar
	@find ${WRKSRC} -name '*.orig' -delete

do-install:
	@cd ${WRKSRC} && tar cf - . | tar xf - -C ${PREFIX}
.for f in ${BINSTUFF}
	@${LN} -fs ${PREFIX}/vje30/bin/$f ${PREFIX}/bin/$f
.endfor
	@${CHMOD} a+x ${PREFIX}/etc/rc.d/vje.sh
	@${CHMOD} a+w ${PREFIX}/vje30/dic/vjed95m.dic
	@[ X${PREFIX} = X"/usr/local" ] || (${LN} -s ${PREFIX}/vje30 /usr/local/; ${LN} -s ${PREFIX}/etc/vje30 /usr/local/etc/)
	@${CP} -Pp /etc/services /etc/services.bak
	@${GREP} -qw '^vjed' /etc/services || ${ECHO} "vjed		11493/tcp		# VJE-Delta Server" >> /etc/services

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
