# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	man-doc
PORTVERSION=	5.4.20050911
PORTREVISION=	3
CATEGORIES=	japanese
.if !defined(WITH_CVS)
MASTER_SITES=	LOCAL/hrs
.else
DISTFILES=	# empty
.endif

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Japanese translation of FreeBSD manual pages

RUN_DEPENDS=	jman:japanese/man

USES=		uidfix
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST=		${WRKDIR}/pkg-plist
MAKE_ENV=	MANDIR=${MANDIR}

MANSECS=	man1 man2 man3 man4 man4/man4.i386 \
		man5 man6 man7 man8 man8/man8.i386 man9
CVSROOT?=	/home/ncvs
CVS_CMD?=	/usr/bin/cvs
JAMANDIR?=	doc/ja_JP.eucJP/man
MANDIR?=	${PREFIX}/man/ja/man

.if defined(WITH_CVS)
do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKDIR} && \
		${CVS_CMD} -R -d ${CVSROOT} co -P -d ${DISTNAME} ${JAMANDIR}
.endif

post-build:
	for SEC in ${MANSECS}; do \
		SECNUM=$${SEC%%/*}; \
		cd ${WRKSRC}/$${SEC} && \
		SUBDIR=`${MAKE} -VMANSUBDIR` && \
		for F in `${MAKE} -VMAN`; do \
			${ECHO_CMD} "man/ja/$${SECNUM}$${SUBDIR}/$${F}.gz"; \
		done; \
		set -- `${MAKE} -VMLINKS`; while :; do \
		case $$# in \
		[01])	break ;; \
		*)	m=$$2; \
			num=$${m##*.}; \
			${ECHO_CMD} "man/ja/man$${num}/$${m}.gz"; \
			shift 2;\
		esac; \
		done; \
	done | ${SORT} -r | uniq > ${PLIST}

pre-install:
	for SEC in ${MANSECS}; do \
		SECNUM=$${SEC%%/*}; \
		cd ${WRKSRC}/$${SEC} && \
		SUBDIR=`${MAKE} -VMANSUBDIR` && \
		${MKDIR} ${STAGEDIR}${PREFIX}/man/ja/$${SECNUM}$${SUBDIR}; \
	done

# XXX: make gendist generates distfile.  Use with WITH_CVS.
gendist: extract
	cd ${WRKDIR} && \
		${FIND} . -type d -a -name CVS | ${XARGS} ${RM} -rf && \
		${TAR} czf ${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}

.include <bsd.port.mk>
