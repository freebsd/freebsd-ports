Index: qemu/hw/serial.c
@@ -196,12 +195,10 @@ static void serial_update_irq(SerialStat
          * this is not in the specification but is observed on existing
          * hardware.  */
         tmp_iir = UART_IIR_CTI;
-    } else if ((s->ier & UART_IER_RDI) && (s->lsr & UART_LSR_DR)) {
-        if (!(s->fcr & UART_FCR_FE)) {
-           tmp_iir = UART_IIR_RDI;
-        } else if (s->recv_fifo.count >= s->recv_fifo.itl) {
-           tmp_iir = UART_IIR_RDI;
-        }
+    } else if ((s->ier & UART_IER_RDI) && (s->lsr & UART_LSR_DR) &&
+               (!(s->fcr & UART_FCR_FE) ||
+                s->recv_fifo.count >= s->recv_fifo.itl)) {
+        tmp_iir = UART_IIR_RDI;
     } else if ((s->ier & UART_IER_THRI) && s->thr_ipending) {
         tmp_iir = UART_IIR_THRI;
     } else if ((s->ier & UART_IER_MSI) && (s->msr & UART_MSR_ANY_DELTA)) {
