# A Makefile for the installed lmbench
BINDIR = ./bin/bsd

results:
	@(cd scripts; ./config-run ../${BINDIR}/CONFIG)
	@(cd scripts; ./results)

rerun:
	@(if [ ! -f ${BINDIR}/CONFIG ]; then \
	  (cd scripts; ./config-run ../${BINDIR}/CONFIG); \
	fi)
	@(cd scripts; ./results)

see:
	cd Results && make summary percent | more
